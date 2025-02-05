#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

const int WIDTH = 50;
const int HEIGHT = 20;

class SnakeGame {
private:
    vector<pair<int, int>> snake;
    int foodX, foodY;
    int score;
    char direction;
    bool gameOver;

public:
    SnakeGame() {
        resetGame();
    }

    void resetGame() {
        snake.clear();
        snake.push_back({WIDTH / 2, HEIGHT / 2});
        score = 0;
        gameOver = false;
        direction = 'r';
        placeFood();
    }

    void placeFood() {
        foodX = rand() % WIDTH;
        foodY = rand() % HEIGHT;
    }

    void draw() {
        system("cls");
        for (int i = 0; i < WIDTH + 2; i++) cout << "#";
        cout << endl;

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                if (x == 0) cout << "#";
                
                bool printed = false;
                for (auto &segment : snake) {
                    if (segment.first == x && segment.second == y) {
                        cout << "O";
                        printed = true;
                        break;
                    }
                }
                
                if (!printed) {
                    if (x == foodX && y == foodY) cout << "F";
                    else cout << " ";
                }
                
                if (x == WIDTH - 1) cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < WIDTH + 2; i++) cout << "#";
        cout << endl;
        cout << "Score: " << score << endl;
    }

    void input() {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'a' && direction != 'r') direction = 'l';
            if (ch == 'd' && direction != 'l') direction = 'r';
            if (ch == 'w' && direction != 'd') direction = 'u';
            if (ch == 's' && direction != 'u') direction = 'd';
            if (ch == 'x') gameOver = true;
        }
    }

    void update() {
        int newX = snake[0].first;
        int newY = snake[0].second;

        if (direction == 'l') newX--;
        if (direction == 'r') newX++;
        if (direction == 'u') newY--;
        if (direction == 'd') newY++;

        if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT) {
            gameOver = true;
            return;
        }

        for (auto &segment : snake) {
            if (segment.first == newX && segment.second == newY) {
                gameOver = true;
                return;
            }
        }

        snake.insert(snake.begin(), {newX, newY});

        if (newX == foodX && newY == foodY) {
            score++;
            placeFood();
        } else {
            snake.pop_back();
        }
    }

    bool isGameOver() {
        return gameOver;
    }

    int getScore() {
        return score;
    }
};

int main() {
    srand(time(0));
    SnakeGame game;

    while (true) {
        while (!game.isGameOver()) {
            game.draw();
            game.input();
            game.update();
            Sleep(150);
        }

        cout << "Game Over! Final Score: " << game.getScore() << endl;
        cout << "Press 'r' to restart or any other key to exit..." << endl;
        char choice = _getch();
        if (choice == 'r' || choice == 'R') {
            game.resetGame();
        } else {
            break;
        }
    }

    return 0;
}
