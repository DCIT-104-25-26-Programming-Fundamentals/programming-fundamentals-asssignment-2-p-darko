// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

void addStudent(vector<Student> &students) {
    Student st;
    cout << "Student name: ";
    getline(cin, st.name);
    if (st.name.empty()) getline(cin, st.name);

    cout << "Student ID: ";
    while (!(cin >> st.id)) {
        cout << "Invalid ID. Enter numeric student ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int totalScores;
    cout << "How many scores? ";
    while (!(cin >> totalScores) || totalScores < 0) {
        cout << "Invalid number. Enter a non-negative integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    st.scores.clear();
    for (int k = 1; k <= totalScores; ++k) {
        double val;
        cout << "Enter score " << k << ": ";
        while (!(cin >> val)) {
            cout << "Invalid score. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        st.scores.push_back(val);
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    students.push_back(st);
    cout << "Student \"" << st.name << "\" added successfully." << endl;
}

double computeAverage(const vector<double> &scores) {
    if (scores.empty()) return 0.0;
    double sum = 0.0;
    for (double val : scores) sum += val;
    return sum / scores.size();
}

void displayAllStudents(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No students found." << endl;
        return;
    }

    cout << left << setw(20) << "Name" << setw(12) << "ID" << setw(20) << "Scores" << "Average" << endl;
    cout << string(60, '-') << endl;

    for (const auto &st : students) {
        cout << left << setw(20) << st.name << setw(12) << st.id;
        
        string scoresFormatted;
        for (size_t k = 0; k < st.scores.size(); ++k) {
            if (k) scoresFormatted += " ";
            scoresFormatted += to_string((long double)st.scores[k]);
        }
        if (scoresFormatted.size() > 18) scoresFormatted = scoresFormatted.substr(0, 17) + "..";
        cout << setw(20) << scoresFormatted;
        cout << fixed << setprecision(2) << computeAverage(st.scores) << defaultfloat << setprecision(6) << endl;
    }
}

void calculateAverageForStudent(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No students available." << endl;
        return;
    }

    cout << "Enter student ID: ";
    int targetId;
    if (!(cin >> targetId)) {
        cout << "Invalid ID." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (const auto &st : students) {
        if (st.id == targetId) {
            double avg = computeAverage(st.scores);
            cout << st.name << "'s average score: " << fixed << setprecision(2) << avg << endl;
            cout << defaultfloat << setprecision(6);
            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (true) {
        cout << "===============================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU" << endl;
        cout << "===============================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";

        if (!(cin >> choice)) {
            cout << "Invalid choice." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayAllStudents(students);
        } else if (choice == 3) {
            calculateAverageForStudent(students);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter 1-4." << endl;
        }
    }

    return 0;
}

