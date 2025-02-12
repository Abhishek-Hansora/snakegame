Snake Game in C++

This project is a simple implementation of the classic Snake game in C++ using the console. It uses basic libraries such as <iostream>, <conio.h>, and <windows.h> to create an interactive game where the player controls a snake to eat food, grow in length, and avoid colliding with walls or itself.

Features

Snake Movement: Use the W, A, S, D keys to control the snake's movement (Up, Left, Down, Right).

Game Over: The game ends when the snake collides with the walls or its own body.

Food: The snake eats food (represented by the 'F' character) to grow longer and increase the score.

Restart Option: After the game ends, the player can restart by pressing the R key or exit by pressing any other key.

Score Display: The current score is displayed at the bottom of the screen and increases every time the snake eats food.

Requirements

A C++ compiler (e.g., GCC, MSVC) that supports C++11 or later.

Windows operating system (due to the usage of <conio.h> and <windows.h>).

Installation

To run this game on your local machine, follow these steps:

Clone the repository:

git clone https://github.com/your-username/snake-game-cpp.git
cd snake-game-cpp

Compile the code:
Use a C++ compiler (e.g., g++, MSVC, or any IDE like Visual Studio) to compile the code:

g++ -o SnakeGame main.cpp

Run the game:

./SnakeGame

How to Play

Movement:

Use W to move up.

Use A to move left.

Use S to move down.

Use D to move right.

Game Over: The game ends if the snake collides with the walls or its own body.

Restart: After the game ends, press R to restart or any other key to exit.

Code Explanation

Class: SnakeGame

This class handles the entire game logic.

Attributes:

snake:

Data type: vector<pair<int, int>>

Description: Stores the coordinates of the snake's body segments.

foodX and foodY:

Data type: int

Description: Stores the coordinates of the food.

score:

Data type: int

Description: Tracks the player's current score.

direction:

Data type: char

Description: Indicates the current direction of the snake ('l' for left, 'r' for right, 'u' for up, 'd' for down).

gameOver:

Data type: bool

Description: Flag that determines if the game is over.

Methods:

resetGame():

Resets the game state by:

Placing the snake in the middle of the screen.

Setting the score to 0.

Resetting the gameOver flag to false.

Setting the initial direction to 'r' (right).

Calling placeFood() to place the food on the screen.

placeFood():

Randomly places the food on the screen within the game boundaries.

Ensures that the food does not spawn on the snake's body.

draw():

Clears the screen and redraws the game board, including:

Walls: Displayed as #.

Snake: Displayed as O.

Food: Displayed as F.

Displays the current score below the game board.

input():

Uses _kbhit() and _getch() to detect user input.

Changes the direction of the snake based on the input:

w for up.

a for left.

s for down.

d for right.

Prevents the snake from reversing direction directly.

Sets gameOver to true if x is pressed.

update():

Moves the snake in the current direction.

Checks for collisions:

Wall collision: Ends the game if the snake moves beyond the screen boundaries.

Self-collision: Ends the game if the snake collides with its own body.

If the snake eats the food:

Increases the score.

Places new food on the screen.

If no food is eaten, removes the tail to simulate movement.

isGameOver():

Returns the current state of the gameOver flag.

getScore():

Returns the current score.

Main Loop:

The main function contains the game loop:

Draws the game board using draw().

Processes user input using input().

Updates the game state using update().

If the game is over, displays the final score and prompts the user to restart or exit.

Data Structures Overview:

Vector of Pairs for Snake:

Stores the coordinates of each segment of the snake.

Allows easy insertion at the front and removal from the back to simulate movement.

Integer Variables for Food and Score:

foodX and foodY store the coordinates of the food.

score tracks the player's current score.

Char for Direction:

Stores the current direction of the snake using single-character codes ('l', 'r', 'u', 'd').

Boolean for Game State:

gameOver is a flag used to determine if the game should continue or end.

Possible Improvements:

Food Placement Validation: Ensure food does not spawn on the snake's body.

Difficulty Levels: Gradually increase the game speed as the score increases.

Borderless Mode: Allow the snake to wrap around the screen instead of colliding with walls.

Pause Functionality: Add the option to pause and resume the game.

High Score Tracking: Display the highest score achieved.

Sound Effects: Add sound effects for events like eating food or game over.

Enjoy playing the Snake Game!
