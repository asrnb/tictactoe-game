// Tic-Tac-Toe in C++ (Compiled Version)
// Suarnaba, Ma. April G. BSCS 4B AI 
// CCS 238 - Programming Language

#include <iostream>     
#include <vector>       // for dynamic arrays
#include <random>       // random numbers
#include <ctime>        // generator with the current time
#include <algorithm>    // To use standard algorithms like sort, shuffle, etc.
#include <tuple>        // For using tuples, a way to store multiple values together
#include <chrono>       // For measuring time intervals (useful for timing code)

using namespace std;
using namespace std::chrono;

// Function to print the current state of the board
void print_board(const vector<vector<char>>& board) {
    int size = board.size();
    cout << "   ";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << "   ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < size; j++) {
            cout << " " << board[i][j] << " ";
            if (j < size - 1) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < size - 1) {
            cout << "   " << string(size * 4 - 1, '-') << endl;
        }
    }
}

// Function to check if the current player has won.
// A player wins with K marks in a row (K = min(size, 5)) in any of the four
// directions: horizontal, vertical, and both diagonals. On a 3x3 board this is
// the classic "full line of 3"; on larger boards it is connect-5, which keeps
// big boards winnable instead of requiring a full 10-in-a-row line.
bool check_win(const vector<vector<char>>& board, char player) {
    int size = board.size();
    int k = min(size, 5);
    const int dirs[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (board[r][c] != player) continue;
            for (const auto& d : dirs) {
                int count = 0, rr = r, cc = c;
                while (rr >= 0 && rr < size && cc >= 0 && cc < size && board[rr][cc] == player) {
                    if (++count == k) return true;
                    rr += d[0];
                    cc += d[1];
                }
            }
        }
    }

    return false;
}

// Function to check if the game is a draw
bool check_draw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

// Function to get the player's move
pair<int, int> get_player_input(const vector<vector<char>>& board, char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter the row (1-" << board.size() << "): ";
        cin >> row;
        cout << "Player " << player << ", enter the column (1-" << board.size() << "): ";
        cin >> col;

        row--; col--;

        int size = static_cast<int>(board.size());
        if (row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ') {
            return {row, col};
        } else {
            cout << "Invalid input or position already taken. Try again." << endl;
        }
    }
}

// AI move based on difficulty levels
pair<int, int> get_ai_move(const vector<vector<char>>& board, const string& difficulty, char ai_player, char human_player) {
    vector<pair<int, int>> empty_cells;

    int size = static_cast<int>(board.size());
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == ' ') {
                empty_cells.push_back({i, j});
            }
        }
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, empty_cells.size() - 1);

    // Easy: Random move
    if (difficulty == "easy") {
        return empty_cells[dis(gen)];
    }

    // Medium: Block player if they are about to win, otherwise random
    if (difficulty == "medium") {
        for (const auto& cell : empty_cells) {
            vector<vector<char>> temp_board = board;
            temp_board[cell.first][cell.second] = human_player;
            if (check_win(temp_board, human_player)) {
                return cell;
            }
        }
        return empty_cells[dis(gen)];
    }

    // Hard: Try to win, block if needed, otherwise random
    if (difficulty == "hard") {
        for (const auto& cell : empty_cells) {
            vector<vector<char>> temp_board = board;
            // Check if AI can win
            temp_board[cell.first][cell.second] = ai_player;
            if (check_win(temp_board, ai_player)) {
                return cell;
            }
        }
        for (const auto& cell : empty_cells) {
            vector<vector<char>> temp_board = board;
            // Check if AI needs to block human player
            temp_board[cell.first][cell.second] = human_player;
            if (check_win(temp_board, human_player)) {
                return cell;
            }
        }
        return empty_cells[dis(gen)];
    }

    // Default to random for safety
    return empty_cells[dis(gen)];
}

// Main function to handle the game logic
void play_game(int size, bool vs_ai, const string& difficulty) {
    vector<vector<char>> board(size, vector<char>(size, ' '));
    char current_player = 'X';
    char ai_player = 'O', human_player = 'X';

    while (true) {
        print_board(board);

        int row, col;
        if (current_player == 'X') {
            tie(row, col) = get_player_input(board, current_player);
        } else {
            if (vs_ai) {
                cout << "AI (" << difficulty << ") is making its move..." << endl;
                
                // Start measuring AI move time
                auto ai_start = high_resolution_clock::now();
                
                tie(row, col) = get_ai_move(board, difficulty, ai_player, human_player);
                
                // End measuring AI move time
                auto ai_end = high_resolution_clock::now();
                auto ai_duration = duration_cast<milliseconds>(ai_end - ai_start).count();
                cout << "AI took " << ai_duration << " milliseconds to make its move." << endl;
            } else {
                tie(row, col) = get_player_input(board, current_player);
            }
        }

        board[row][col] = current_player;

        if (check_win(board, current_player)) {
            print_board(board);
            cout << "Player " << current_player << " wins!" << endl;
            break;
        } else if (check_draw(board)) {
            print_board(board);
            cout << "It's a draw!" << endl;
            break;
        }

        current_player = (current_player == 'X') ? 'O' : 'X';
    }
}

int main() {
    // Start measuring overall execution time
    auto start_time = high_resolution_clock::now();

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (true) {
        int size;
        cout << "Choose the grid size (3 for 3x3, up to 10 for 10x10): ";
        cin >> size;

        if (size >= 3 && size <= 10) {
            string response;
            cout << "Do you want to play against the AI? (yes/no): ";
            cin >> response;

            bool vs_ai = (response == "yes");
            string difficulty = "easy";  // Default difficulty

            if (vs_ai) {
                cout << "Choose AI difficulty (easy, medium, hard): ";
                cin >> difficulty;
                if (difficulty != "easy" && difficulty != "medium" && difficulty != "hard") {
                    cout << "Invalid difficulty. Defaulting to 'easy'." << endl;
                    difficulty = "easy";
                }
            }

            play_game(size, vs_ai, difficulty);
            break;
        } else {
            cout << "Please select a valid option between 3 and 10." << endl;
        }
    }

    // End measuring overall execution time
    auto end_time = high_resolution_clock::now();
    auto total_duration = duration_cast<seconds>(end_time - start_time).count();
    cout << "Total execution time: " << total_duration << " seconds." << endl;

    return 0;
}
