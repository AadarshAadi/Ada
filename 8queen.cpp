#include <iostream>
using namespace std;

#define N 8

// Utility function to print the board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check this row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) return false;
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueensUtil(int board[N][N], int col) {
    // If all queens are placed
    if (col >= N) return true;

    // Try placing queen in each row of the current column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;  // Place queen

            // Recur to place the rest of the queens
            if (solveNQueensUtil(board, col + 1)) return true;

            board[i][col] = 0;  // Backtrack
        }
    }

    return false;  // No placement possible for this column
}

// Function to solve the N-Queens problem
bool solveNQueens() {
    int board[N][N] = {0};  // Initialize board with zeros

    if (!solveNQueensUtil(board, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    printBoard(board);  // Print the solution
    return true;
}

int main() {
    
    solveNQueens();
    return 0;
}
