// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

// Addition Function
double add(double val1, double val2) {
    return val1 + val2;
}

// Subtraction Function
double subtractNums(double val1, double val2) {
    return val1 - val2;
}

// Multiplication Function
double multiply(double val1, double val2) {
    return val1 * val2;
}

// Division Function: returns false on division by zero
bool divide(double val1, double val2, double &output) {
    if (val2 == 0.0) return false;
    output = val1 / val2;
    return true;
}

// Modulus: integer remainder, returns false on divide by zero
bool calculateModulus(int val1, int val2, int &output) {
    if (val2 == 0) return false;
    output = val1 % val2;
    return true;
}

// Exponentiation
double exponentiate(double baseVal, double expVal) {
    return pow(baseVal, expVal);
}

int main() {
    int choice = 0;
    while (true) {
        cout << "============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";

        if (!(cin >> choice)) {
            cout << "Invalid choice." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        cout << fixed << setprecision(2);

        if (choice >= 1 && choice <= 4) {
            double num1, num2;
            cout << "Enter first number : ";
            while (!(cin >> num1)) {
                cout << "Invalid input. Enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter second number: ";
            while (!(cin >> num2)) {
                cout << "Invalid input. Enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (choice == 1) {
                double calcResult = add(num1, num2);
                cout << "Result: " << num1 << " + " << num2 << " = " << calcResult << endl;
            } else if (choice == 2) {
                double calcResult = subtractNums(num1, num2);
                cout << "Result: " << num1 << " - " << num2 << " = " << calcResult << endl;
            } else if (choice == 3) {
                double calcResult = multiply(num1, num2);
                cout << "Result: " << num1 << " * " << num2 << " = " << calcResult << endl;
            } else if (choice == 4) {
                double calcResult;
                if (!divide(num1, num2, calcResult)) {
                    cout << "Error: Cannot divide by zero." << endl;
                } else {
                    cout << "Result: " << num1 << " / " << num2 << " = " << calcResult << endl;
                }
            }
        }
        else if (choice == 5) {
            int int1, int2;
            cout << "Enter first integer : ";
            while (!(cin >> int1)) {
                cout << "Invalid input. Enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter second integer: ";
            while (!(cin >> int2)) {
                cout << "Invalid input. Enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            int calcResult;
            if (!calculateModulus(int1, int2, calcResult)) {
                cout << "Error: Cannot modulus by zero." << endl;
            } else {
                cout << "Result: " << int1 << " % " << int2 << " = " << calcResult << endl;
            }
        }
        else if (choice == 6) {
            double baseVal, expVal;
            cout << "Enter base: ";
            while (!(cin >> baseVal)) {
                cout << "Invalid input. Enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter exponent: ";
            while (!(cin >> expVal)) {
                cout << "Invalid input. Enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            double calcResult = exponentiate(baseVal, expVal);
            cout << "Result: " << baseVal << " ^ " << expVal << " = " << calcResult << endl;
        }
        else {
            cout << "Invalid choice. Please select 1-7." << endl;
        }

        cout << defaultfloat << setprecision(6);
    }

    return 0;
}

