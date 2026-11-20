
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const string RESET = "\033[0m";
const string BLUE = "\033[94m";
const string RED = "\033[91m";
const string GREEN = "\033[92m";
const string YELLOW = "\033[93m";
const string CYAN = "\033[96m";

char board[3][3];
int scoreX = 0, scoreO = 0, draws = 0;

// Initialize the board
void resetBoard() {
    char value = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = value++;
        }
    }
}

// Display game title
void showTitle() {
    cout << CYAN;
    cout << "\n====================================\n";
    cout << "          TIC TAC TOE GAME          \n";
    cout << "             VERSION 2.0            \n";
    cout << "====================================\n";
    cout << RESET;
}

// Display board
void displayBoard() {
    cout << "\n";

    for (int i = 0; i < 3; i++) {
        cout << "          ";

        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X')
                cout << BLUE << "X" << RESET;
            else if (board[i][j] == 'O')
                cout << RED << "O" << RESET;
            else
                cout << YELLOW << board[i][j] << RESET;

            if (j < 2) cout << "  |  ";
        }

        cout << "\n";

        if (i < 2)
            cout << "         -----+-----+-----\n";
    }

    cout << "\n";
}

// Check winner
bool checkWinner(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

// Check draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

// Read valid integer input
int getInput() {
    string line;
    int number;
    char extra;

    while (true) {
        getline(cin, line);

        stringstream ss(line);

        if (ss >> number && !(ss >> extra))
            return number;

        cout << RED << "Invalid input! Enter a number: "
             << RESET;
    }
}

// Display scoreboard
void showScore() {
    cout << CYAN;
    cout << "\n========== SCOREBOARD ==========\n";
    cout << RESET;

    cout << BLUE << "Player X Wins: " << scoreX << RESET << "\n";
    cout << RED << "Player O Wins: " << scoreO << RESET << "\n";
    cout << YELLOW << "Draws: " << draws << RESET << "\n";

    cout << "================================\n";
}

// Play game
void playGame() {
    resetBoard();

    char currentPlayer = 'X';

    while (true) {
        displayBoard();

        if (currentPlayer == 'X')
            cout << BLUE << "Player X's Turn\n" << RESET;
        else
            cout << RED << "Player O's Turn\n" << RESET;

        cout << "Choose position (1-9): ";

        int choice = getInput();

        if (choice < 1 || choice > 9) {
            cout << RED << "Choose between 1 and 9!\n" << RESET;
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' ||
            board[row][col] == 'O') {
            cout << RED << "Position already occupied!\n" << RESET;
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWinner(currentPlayer)) {
            displayBoard();

            cout << GREEN << "\nCongratulations! Player "
                 << currentPlayer << " WINS!\n" << RESET;

            if (currentPlayer == 'X')
                scoreX++;
            else
                scoreO++;

            break;
        }

        if (checkDraw()) {
            displayBoard();

            cout << YELLOW << "\nGAME DRAW!\n" << RESET;
            draws++;

            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    showScore();
}

// Instructions
void showInstructions() {
    cout << CYAN;
    cout << "\n========== HOW TO PLAY ==========\n";
    cout << RESET;

    cout << "1. This is a two-player game.\n";
    cout << "2. Player X plays first.\n";
    cout << "3. Player O plays second.\n";
    cout << "4. Choose a position from 1 to 9.\n";
    cout << "5. Get three symbols in a row to win.\n";
    cout << "6. Rows, columns and diagonals count.\n";
    cout << "7. If all positions are filled without a winner, it is a draw.\n";

    cout << "=================================\n";
}

// Main menu
int main() {
    int choice;

    while (true) {
        showTitle();

        cout << "\n";
        cout << GREEN << "1. Start New Game\n" << RESET;
        cout << CYAN << "2. Instructions\n" << RESET;
        cout << YELLOW << "3. View Scoreboard\n" << RESET;
        cout << RED << "4. Exit Game\n" << RESET;

        cout << "\nEnter your choice: ";

        choice = getInput();

        switch (choice) {
            case 1:
                playGame();
                break;

            case 2:
                showInstructions();
                break;

            case 3:
                showScore();
                break;

            case 4:
                cout << GREEN << "\nThank you for playing!\n" << RESET;
                cout << "Goodbye!\n";
                return 0;

            default:
                cout << RED << "Invalid menu choice!\n" << RESET;
        }

        cout << "\nPress Enter to return to the main menu...";
        string pause;
        getline(cin, pause);
    }

    return 0;
}
