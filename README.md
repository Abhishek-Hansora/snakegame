# Snake Game in C++

This is a simple implementation of the classic Snake game in C++ using the console. It utilizes basic libraries such as `<iostream>`, `<conio.h>`, and `<windows.h>` to create an interactive and fun game where the player controls a snake that moves around the screen, eats food to grow longer, and avoids colliding with the walls or itself.

## Features
- **Snake Movement**: Use the `W`, `A`, `S`, `D` keys to control the snake's movement (Up, Left, Down, Right).
- **Game Over**: The game ends when the snake collides with the walls or its own body.
- **Food**: The snake must eat food (`F` character) to grow in length and increase the score.
- **Restart Option**: After the game is over, the player can restart by pressing the `R` key, or exit the game by pressing any other key.
- **Score**: The score is displayed at the bottom of the screen, and increases every time the snake eats food.

## Requirements
- A C++ compiler (e.g., GCC, MSVC) supporting C++11 or later.
- **Windows** operating system (because of `conio.h` and `windows.h` usage).

## Installation
To run this game on your local machine, follow these steps:
   

1. **Compile the Code**:
   Using a C++ compiler (like `g++` or MSVC), compile the `main.cpp` file:
    - On Windows, you can use MSVC or any IDE that supports C++ (like Visual Studio) to compile the code.

2. **Run the Game**:
   After compiling, run the executable to start playing the game.

## How to Play

- **Movement**: 
  - Use `W` to move up.
  - Use `A` to move left.
  - Use `S` to move down.
  - Use `D` to move right.
  
- **Game Over**: The game ends if the snake collides with the walls or its own body.
  
- **Restart**: After the game ends, you will see a prompt. Press `R` to restart the game or any other key to exit.

## Code Explanation

### Class: `SnakeGame`
- **Attributes**:
  - `snake`: A vector of pairs that stores the coordinates of the snake's body.
  - `foodX`, `foodY`: The coordinates where food appears on the screen.
  - `score`: Tracks the player's score.
  - `direction`: Stores the current direction of the snake (`'l'`, `'r'`, `'u'`, `'d'` for left, right, up, and down).
  - `gameOver`: Boolean flag that indicates whether the game is over.

- **Methods**:
  - `resetGame()`: Resets the game state, placing the snake in the middle of the screen and resetting the score.
  - `placeFood()`: Randomly places the food on the screen.
  - `draw()`: Draws the current game state (snake, food, and score) on the screen.
  - `input()`: Handles user input (W, A, S, D for movement and X to quit).
  - `update()`: Updates the game state by moving the snake, checking for collisions, and updating the score when food is eaten.
  - `isGameOver()`: Returns whether the game is over.
  - `getScore()`: Returns the current score.

### Main Loop:
1. **Draw** the game board.
2. **Input** the user's movement.
3. **Update** the game state by moving the snake.
4. If the game is over, display the final score and prompt the user to restart or quit.

## Data Structure Analysis

### 1. **Vector of Pairs for Snake**
   - **Data Structure**: `vector<pair<int, int>>`
   - **Explanation**: 
     The snake's body is represented as a vector of pairs. Each `pair<int, int>` holds the coordinates of a segment of the snake. The first element of the pair represents the `x` coordinate, and the second element represents the `y` coordinate of a segment.
     The snake's body grows as new segments are added to the front of the vector whenever the snake eats food, and the last segment is removed when it doesn't.

   - **Usage**: 
     - The snake's body is stored dynamically, and its size changes as the snake eats food.
     - The `vector` allows easy insertion at the front (`insert()`) and removal from the back (`pop_back()`).

### 2. **Integer Variables for Food and Score**
   - **Data Structure**: `int foodX, foodY, score`
   - **Explanation**:
     - `foodX` and `foodY` store the coordinates of the food on the screen.
     - `score` keeps track of the player's score, which increases each time the snake eats food.

   - **Usage**: 
     - Simple integers are sufficient for these variables because we only need to store a fixed set of data (coordinates and score).

### 3. **Char for Direction**
   - **Data Structure**: `char direction`
   - **Explanation**:
     - The `direction` variable stores the current direction of the snake using a single character: `'l'` for left, `'r'` for right, `'u'` for up, and `'d'` for down.
   
   - **Usage**: 
     - This variable helps in determining how the snake's position should be updated in each game loop, and ensures that the snake cannot reverse direction directly.

### 4. **Boolean for Game State**
   - **Data Structure**: `bool gameOver`
   - **Explanation**: 
     - The `gameOver` boolean flag is used to determine whether the game is over. It is set to `true` if the snake collides with the wall or itself, and the game loop ends when it is `true`.

   - **Usage**:
     - This is a simple boolean that prevents further movement updates and input processing once the game ends.

### 5. **Food Placement (Random Coordinates)**
   - **Data Structure**: The `placeFood()` method generates random coordinates for the food by using `rand() % WIDTH` and `rand() % HEIGHT` to place the food in random locations on the screen.

   - **Usage**:
     - Random placement ensures that the food appears in different locations each time it is eaten.


Enjoy playing!

