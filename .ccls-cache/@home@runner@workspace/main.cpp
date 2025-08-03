#include <iostream>
using namespace std;

const int SIZE = 3;
const char EMPTY = '*';

void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(const char board[SIZE][SIZE]);
void placeToken(char board[SIZE][SIZE], char token);
void getLocation(int &row, int &col, const char board[SIZE][SIZE]);
bool checkWinner(const char board[SIZE][SIZE], char token);
bool isBoardFull(const char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);

    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        displayBoard(board);
        cout << "Player " << (currentPlayer == 'X' ? 1 : 2) << "'s turn (" << currentPlayer << ")" << endl;

        placeToken(board, currentPlayer);

        if (checkWinner(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << (currentPlayer == 'X' ? 1 : 2) << " wins!" << endl;
            gameOver = true;
        } else if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a tie!" << endl;
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = EMPTY;
}

void displayBoard(const char board[SIZE][SIZE]) {
    cout << "\n  1 2 3\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void placeToken(char board[SIZE][SIZE], char token) {
    int row, col;
    getLocation(row, col, board);
    board[row][col] = token;
}

void getLocation(int &row, int &col, const char board[SIZE][SIZE]) {
    while (true) {
        cout << "Enter row (1-3): ";
        cin >> row;
        cout << "Enter column (1-3): ";
        cin >> col;

        row--; col--;

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
            if (board[row][col] == EMPTY) {
                return;
            } else {
                cout << "That spot is already taken. Try again.\n";
            }
        } else {
            cout << "Invalid coordinates. Please enter numbers between 1 and 3.\n";
        }
    }
}

bool checkWinner(const char board[SIZE][SIZE], char token) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == token && board[i][1] == token && board[i][2] == token) || 
            (board[0][i] == token && board[1][i] == token && board[2][i] == token))
            return true;
    }

    // Check diagonals
    if ((board[0][0] == token && board[1][1] == token && board[2][2] == token) ||
        (board[0][2] == token && board[1][1] == token && board[2][0] == token))
        return true;

    return false;
}

bool isBoardFull(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == EMPTY)
                return false;
    return true;
}
