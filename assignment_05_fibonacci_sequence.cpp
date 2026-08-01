// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

void printFibonacci(int val) {
    if (val <= 0) {
        cout << "Error: Number of terms must be positive." << endl;
        return;
    }
    
    cout << "Fibonacci sequence: ";
    if (val >= 1) cout << "0";
    if (val >= 2) cout << " 1";
    
    if (val > 2) {
        int a = 0, b = 1;
        for (int i = 3; i <= val; i++) {
            int c = a + b;
            cout << " " << c;
            a = b;
            b = c;
        }
    }
    cout << endl;
}

bool isFibonacci(int target) {
    if (target < 0) return false;
    if (target == 0 || target == 1) return true;
    
    int a = 0, b = 1;
    while (b < target) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b == target;
}

int main() {
    int choice;
    
    cout << "Fibonacci Program" << endl;
    cout << "1. Print first N terms" << endl;
    cout << "2. Check if a number is Fibonacci" << endl;
    cout << "Enter your choice (1-2): ";
    cin >> choice;
    
    if (choice == 1) {
        int n;
        cout << "How many terms? ";
        cin >> n;
        printFibonacci(n);
    }
    else if (choice == 2) {
        int num;
        cout << "Enter a number to check: ";
        cin >> num;
        
        if (isFibonacci(num)) {
            cout << num << " is a Fibonacci number." << endl;
        } else {
            cout << num << " is NOT a Fibonacci number." << endl;
        }
    }
    else {
        cout << "Invalid choice!" << endl;
    }
    
    return 0;
}

