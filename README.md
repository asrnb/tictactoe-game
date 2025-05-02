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
  
- **Dynamic Board Size**: Players can choose between two grid sizes:
  - 3x3
  - 10x10
  
- **Win/Draw Detection**: After each turn, the game checks for a winner or a draw.

- **AI Implementation**: The AI uses a basic strategy (like random moves or minimax) to make decisions in the **Human vs AI** mode.

## Programming Languages

This project has been implemented in two different programming languages:

1. **C++**: Known for its high performance and speed, making it ideal for performance comparison.
2. **Python**: A more user-friendly language, offering simplicity at the cost of execution speed, making it suitable for comparison in terms of development time and ease of use.

Each implementation provides the same gameplay functionality, allowing for a side-by-side performance comparison.

## Installation

1. **Clone the repository:**

    ```bash
    git clone https://github.com/yourusername/tic-tac-toe.git
    ```

2. **Navigate to the project directory:**

    ```bash
    cd tic-tac-toe
    ```

3. **For C++:**

    - Make sure you have a C++ compiler (e.g., `g++`) installed.
    - Compile the C++ source code:

    ```bash
    g++ cpp_version/tic_tac_toe.cpp -o tic_tac_toe_cpp
    ```

    - Run the compiled executable:

    ```bash
    ./tic_tac_toe_cpp
    ```

4. **For Python:**

    - Ensure that Python is installed (preferably Python 3.x).
    - Install required dependencies (if any):

    ```bash
    pip install -r python_version/requirements.txt
    ```

    - Run the Python game:

    ```bash
    python python_version/tic_tac_toe.py
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
