# Tic-Tac-Toe in Python (Interpreted Version)
#Suarnaba, Ma. April G. BSCS 4B AI 
#CCS 238 - Programming Language

import random
import time

# Function to print the current state of the board
def print_board(board):
    size = len(board)
    print("   " + "   ".join([str(i+1) for i in range(size)]))  # Column headers
    for i, row in enumerate(board):
        print(f"{i+1:2} " + " | ".join(row))  # Row number with formatting for two digits
        if i < size - 1:
            print("   " + "-" * (size * 4 - 1))

# Function to check if the current player has won
def check_win(board, player):
    size = len(board)
    for i in range(size):
        if all([cell == player for cell in board[i]]) or all([board[j][i] == player for j in range(size)]):
            return True
    if all([board[i][i] == player for i in range(size)]) or all([board[i][size-i-1] == player for i in range(size)]):
        return True
    return False

# Function to check if the board is full, resulting in a draw
def check_draw(board):
    return all([cell != ' ' for row in board for cell in row])

# Function to get the player's move (row and column)
def get_player_input(board, player):
    while True:
        try:
            row = int(input(f"Player {player}, enter the row (1-{len(board)}): ")) - 1
            col = int(input(f"Player {player}, enter the column (1-{len(board)}): ")) - 1
            if board[row][col] == ' ':
                return row, col
            else:
                print("This position is already taken. Try again.")
        except (ValueError, IndexError):
            print(f"Please enter valid numbers between 1 and {len(board)}.")

# AI moves based on difficulty levels
def get_ai_move(board, difficulty, player, opponent):
    empty_cells = [(i, j) for i in range(len(board)) for j in range(len(board[i])) if board[i][j] == ' ']

    if difficulty == "easy":
        # Easy: Random move
        return random.choice(empty_cells)
    
    elif difficulty == "medium":
        # Medium: Block player if they are about to win
        for row, col in empty_cells:
            # Check if AI can block the opponent from winning
            board[row][col] = opponent
            if check_win(board, opponent):
                board[row][col] = ' '
                return (row, col)
            board[row][col] = ' '
        # If no block is needed, pick random
        return random.choice(empty_cells)
    
    elif difficulty == "hard":
        # Hard: Try to win or block the opponent
        for row, col in empty_cells:
            # Check if AI can win
            board[row][col] = player
            if check_win(board, player):
                board[row][col] = ' '
                return (row, col)
            board[row][col] = ' '
        
        # Check if AI needs to block
        for row, col in empty_cells:
            board[row][col] = opponent
            if check_win(board, opponent):
                board[row][col] = ' '
                return (row, col)
            board[row][col] = ' '
        
        # Otherwise, pick a random move
        return random.choice(empty_cells)

# Main function to run the game
def play_game(size, vs_ai=False, difficulty="easy", score=None):
    if score is None:
        score = {"Player X": 0, "Player O": 0}

    board = [[' ' for _ in range(size)] for _ in range(size)]
    current_player = 'X'
    opponent = 'O'

    while True:
        print_board(board)
        if current_player == 'X':
            row, col = get_player_input(board, current_player)
        else:
            if vs_ai:
                print(f"AI ({difficulty.capitalize()}) is making its move...")
                start_time = time.time()  # Start the timer for AI move
                row, col = get_ai_move(board, difficulty, current_player, 'X')
                end_time = time.time()  # End the timer for AI move
                elapsed_time = end_time - start_time  # Calculate elapsed time for AI move
                print(f"AI took {elapsed_time:.2f} seconds to make its move.")
            else:
                row, col = get_player_input(board, current_player)

        board[row][col] = current_player

        if check_win(board, current_player):
            print_board(board)
            print(f"Player {current_player} wins!")
            score[f"Player {current_player}"] += 1
            break
        elif check_draw(board):
            print_board(board)
            print("It's a draw!")
            break

        current_player = 'O' if current_player == 'X' else 'X'

    return score

# Main entry point
def main():
    print("Welcome to Tic-Tac-Toe!")
    score = {"Player X": 0, "Player O": 0}
    
    total_start_time = time.time()  # Start timing the total program execution
    
    while True:
        try:
            size = int(input("Choose the grid size (3 for 3x3, up to 10 for 10x10): "))
            if 3 <= size <= 10:
                vs_ai = input("Do you want to play against the AI? (yes/no): ").lower() == "yes"
                if vs_ai:
                    difficulty = input("Choose AI difficulty (easy, medium, hard): ").lower()
                    if difficulty not in ["easy", "medium", "hard"]:
                        print("Invalid difficulty. Defaulting to 'easy'.")
                        difficulty = "easy"
                else:
                    difficulty = "easy"  # Default difficulty for Player vs AI

                score = play_game(size, vs_ai, difficulty, score)
                print("\nScoreboard:")
                print(f"Player X: {score['Player X']}")
                print(f"Player O: {score['Player O']}")
                play_again = input("Do you want to play again? (yes/no): ").lower()
                if play_again != "yes":
                    print("Thank you for playing!")
                    break
            else:
                print("Please select a valid option between 3 and 10.")
        except ValueError:
            print("Please enter a valid number.")

    total_end_time = time.time()  # End timing the total program execution
    total_elapsed_time = total_end_time - total_start_time  # Calculate the total time taken
    print(f"\nTotal execution time: {total_elapsed_time:.2f} seconds")

# Ensure the main function runs when the script is executed
if __name__ == "__main__":
    main()
