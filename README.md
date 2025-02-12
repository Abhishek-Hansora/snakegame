# Snake Game in C++

This is a simple implementation of the classic Snake game in C++ using the console. It utilizes basic libraries such as `<iostream>`, `<conio.h>`, and `<windows.h>` to create an interactive and fun game.

## Features
- **Snake Movement**: Use the `W`, `A`, `S`, `D` keys to control the snake's movement (Up, Left, Down, Right).
- **Game Over**: The game ends when the snake collides with the walls or its own body.
- **Food**: The snake must eat food (`F` character) to grow in length and increase the score.
- **Restart Option**: After the game is over, the player can restart by pressing the `R` key, or exit the game by pressing any other key.
- **Score**: The score is displayed at the bottom of the screen and increases every time the snake eats food.

## Requirements
- A C++ compiler (e.g., GCC, MSVC) supporting C++11 or later.
- **Windows** operating system (because of `conio.h` and `windows.h` usage).


How to Play
Movement:

W: Move up.
A: Move left.
S: Move down.
D: Move right.
Game Over: The game ends if the snake collides with the walls or its own body.

Restart: After the game ends, press R to restart or any other key to exit.

Code Explanation
Class: SnakeGame
The game logic is implemented in the SnakeGame class.

Attributes
snake: A vector of pairs that stores the coordinates of the snake's body.
foodX, foodY: The coordinates where food appears on the screen.
score: Tracks the player's score.
direction: Stores the current direction of the snake ('l', 'r', 'u', 'd' for left, right, up, and down).
gameOver: Boolean flag that indicates whether the game is over.
Methods
resetGame(): Resets the game state by:

Placing the snake in the middle of the screen.
Setting the score to 0.
Resetting the gameOver flag to false.
Setting the initial direction to 'r' (right).
Calling placeFood() to place the food on the screen.
placeFood(): Randomly places the food on the screen within the game boundaries while ensuring it does not spawn on the snake's body.

draw(): Clears the screen and redraws the game board, including:

Walls: Displayed as #.
Snake: Displayed as O.
Food: Displayed as F.
Displays the current score below the game board.
input(): Detects user input using _kbhit() and _getch(). Updates the snake's direction based on the input:

'w' for up.
'a' for left.
's' for down.
'd' for right.
Ends the game if 'x' is pressed.
update(): Updates the game state by:

Moving the snake in the current direction.
Checking for collisions:
Wall collision: Ends the game if the snake moves beyond the screen boundaries.
Self-collision: Ends the game if the snake collides with its own body.
If the snake eats the food:
Increases the score.
Places new food on the screen.
If no food is eaten, removes the tail to simulate movement.
isGameOver(): Returns whether the game is over.

getScore(): Returns the current score.

Main Loop
Draw the game board using draw().
Process Input using input().
Update the game state using update().
If the game is over, display the final score and prompt the user to restart or exit.
Data Structure Analysis
1. Vector of Pairs for Snake
Data Structure: vector<pair<int, int>>
Usage:
Stores the coordinates of each segment of the snake.
Allows easy insertion at the front and removal from the back to simulate movement.
2. Integer Variables for Food and Score
Data Structure: int foodX, foodY, score
Usage:
foodX and foodY store the coordinates of the food.
score tracks the player's score.
3. Char for Direction
Data Structure: char direction
Usage:
Stores the current direction of the snake.
4. Boolean for Game State
Data Structure: bool gameOver
Usage:
Indicates whether the game is over.
5. Food Placement (Random Coordinates)
The placeFood() method generates random coordinates for the food using rand() % WIDTH and rand() % HEIGHT.

Possible Improvements
Food Placement Validation: Ensure food does not spawn on the snake's body.
Difficulty Levels: Gradually increase the game speed as the score increases.
Borderless Mode: Allow the snake to wrap around the screen instead of colliding with walls.
Pause Functionality: Add the option to pause and resume the game.
High Score Tracking: Display the highest score achieved.
Sound Effects: Add sound effects for events like eating food or game over.
Enjoy playing the Snake Game!
