// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

int getSum(int numbers[], int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += numbers[i];
    }
    return total;
}

double getAverage(int numbers[], int count) {
    return static_cast<double>(getSum(numbers, count)) / count;
}

int getMax(int numbers[], int count) {
    int highest = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] > highest) highest = numbers[i];
    }
    return highest;
}

int getMin(int numbers[], int count) {
    int lowest = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] < lowest) lowest = numbers[i];
    }
    return lowest;
}

int main() {
    int size;
    cout << "How many numbers? ";
    cin >> size;

    if (size <= 0) {
        cout << "Error: Number of elements must be positive." << endl;
        return 0;
    }

    int values[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> values[i];
    }

    cout << "\nResults:" << endl;
    cout << "Sum:     " << getSum(values, size) << endl;
    cout << "Average: " << getAverage(values, size) << endl;
    cout << "Maximum: " << getMax(values, size) << endl;
    cout << "Minimum: " << getMin(values, size) << endl;

    return 0;
}
