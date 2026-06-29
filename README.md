# Tic-Tac-Toe Game

## Objective

This project implements a **Tic-Tac-Toe** game with two gameplay modes:

- **Human vs Human**
- **Human vs AI**

The game features a dynamic board size, allowing players to choose between a 3x3 and a 10x10 grid. Players alternate turns, marking their moves with 'X' and 'O', and the game continuously checks for a win or draw after every turn.

The primary goal of this project is to compare the **performance** and **speed** of two different programming languages—C++ and Python—in implementing the same game logic.

## Features

- **Two Gameplay Modes:**
  - **Human vs Human**: Two players take turns marking 'X' and 'O'.
  - **Human vs AI**: One player competes against an AI, with the AI making strategic moves.
  
- **Dynamic Board Size**: Players can choose any square grid from **3x3 up to 10x10**.

- **Win/Draw Detection**: After each turn, the game checks for a winner or a draw.
  - **Win condition:** a player wins by getting **K in a row** (horizontally, vertically, or diagonally), where `K = min(board size, 5)`. On a 3x3 board this is the classic "full line of 3"; on larger boards it is connect-5, which keeps big boards actually winnable.

- **AI Implementation**: The AI uses heuristic strategies in the **Human vs AI** mode, selectable by difficulty:
  - **easy** – random valid move
  - **medium** – blocks the opponent's immediate winning move, otherwise random
  - **hard** – takes its own immediate winning move, else blocks the opponent, otherwise random

## Programming Languages

This project has been implemented in two different programming languages:

1. **C++**: Known for its high performance and speed, making it ideal for performance comparison.
2. **Python**: A more user-friendly language, offering simplicity at the cost of execution speed, making it suitable for comparison in terms of development time and ease of use.

Each implementation provides the same gameplay functionality, allowing for a side-by-side performance comparison.

## Installation

1. **Clone the repository:**

    ```bash
    git clone https://github.com/asrnb/tictactoe-game.git
    ```

2. **Navigate to the project directory:**

    ```bash
    cd tictactoe-game
    ```

3. **For C++:**

    - Make sure you have a C++ compiler (e.g., `g++`) installed.
    - Compile the C++ source code (C++11 or newer):

    ```bash
    g++ -std=c++11 -O2 tictactoe_cpp.cpp -o tictactoe_cpp
    ```

    - Run the compiled executable:

    ```bash
    ./tictactoe_cpp
    ```

4. **For Python:**

    - Ensure that Python 3.x is installed. The game uses only the standard
      library, so there are no extra dependencies to install.

    ```bash
    python tictactoe_py.py
    ```

## Usage

- **Human vs Human**: Players take turns, inputting the corresponding grid position (e.g., "1" for top-left).
  
- **Human vs AI**: The AI automatically makes its move after the player.

- The board size can be chosen at the start of the game (either 3x3 or 10x10).

## Performance Comparison

The game’s performance will be analyzed based on:

- **Execution Speed**: Measure the time taken for each turn, including AI decision-making.
- **Turn Transitions**: Compare how quickly the game progresses in both languages.
- **AI Decision-Making Time**: Evaluate the time the AI takes to make a move in **Human vs AI** mode.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
