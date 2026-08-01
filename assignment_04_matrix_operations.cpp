// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int &r, int &c) {
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int r, int c, int res[MAX_SIZE][MAX_SIZE], int &nR, int &nC) {
    nR = c;
    nC = r;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[j][i] = mat[i][j];
        }
    }
}

void addMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void multiplyMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int rA, int cA, int rB, int cB) {
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            res[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                res[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int choice;
    int rows, cols, rowsB, colsB;
    
    cout << "Matrix Operations Menu" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    if (choice == 1) {
        cout << "\n--- Part A: Transpose a Matrix ---" << endl;
        readMatrix(matrixA, rows, cols);
        
        cout << "\nOriginal Matrix:" << endl;
        displayMatrix(matrixA, rows, cols);
        
        int newRows, newCols;
        transposeMatrix(matrixA, rows, cols, result, newRows, newCols);
        
        cout << "\nTransposed Matrix:" << endl;
        displayMatrix(result, newRows, newCols);
    }
    else if (choice == 2) {
        cout << "\n--- Part B: Add Two Matrices ---" << endl;
        cout << "Enter Matrix A:" << endl;
        readMatrix(matrixA, rows, cols);
        
        cout << "\nEnter Matrix B (same size as Matrix A):" << endl;
        readMatrix(matrixB, rowsB, colsB);
        
        if (rows != rowsB || cols != colsB) {
            cout << "Error: Matrices must have the same dimensions!" << endl;
            return 0;
        }
        
        addMatrices(matrixA, matrixB, result, rows, cols);
        
        cout << "\nMatrix A:" << endl;
        displayMatrix(matrixA, rows, cols);
        
        cout << "\nMatrix B:" << endl;
        displayMatrix(matrixB, rowsB, colsB);
        
        cout << "\nSum (A + B):" << endl;
        displayMatrix(result, rows, cols);
    }
    else if (choice == 3) {
        cout << "\n--- Part C: Multiply Two Matrices ---" << endl;
        cout << "Enter Matrix A:" << endl;
        readMatrix(matrixA, rows, cols);
        
        cout << "\nEnter Matrix B (rows must equal columns of Matrix A):" << endl;
        readMatrix(matrixB, rowsB, colsB);
        
        if (cols != rowsB) {
            cout << "Error: Columns of A must equal rows of B!" << endl;
            return 0;
        }
        
        multiplyMatrices(matrixA, matrixB, result, rows, cols, rowsB, colsB);
        
        cout << "\nMatrix A (" << rows << " x " << cols << "):" << endl;
        displayMatrix(matrixA, rows, cols);
        
        cout << "\nMatrix B (" << rowsB << " x " << colsB << "):" << endl;
        displayMatrix(matrixB, rowsB, colsB);
        
        cout << "\nProduct (A x B) (" << rows << " x " << colsB << "):" << endl;
        displayMatrix(result, rows, colsB);
    }
    else {
        cout << "Invalid choice!" << endl;
    }
    
    return 0;
}

