// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addTask(vector<string> &todoList) {
    cout << "Enter task: ";
    string item;
    getline(cin, item);
    if (item.empty()) getline(cin, item);
    todoList.push_back(item);
    cout << "Task added: \"" << item << "\"" << endl;
}

void viewTasks(const vector<string> &todoList) {
    if (todoList.empty()) {
        cout << "No tasks found. Your to-do list is empty." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;
    for (size_t k = 0; k < todoList.size(); ++k) {
        cout << (k + 1) << ". " << todoList[k] << endl;
    }
}

void deleteTask(vector<string> &todoList) {
    if (todoList.empty()) {
        cout << "No tasks to delete." << endl;
        return;
    }

    cout << "Enter task number to delete: ";
    int target;
    if (!(cin >> target)) {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    if (target < 1 || target > static_cast<int>(todoList.size())) {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    string deletedItem = todoList[target - 1];
    todoList.erase(todoList.begin() + (target - 1));
    cout << "Task \"" << deletedItem << "\" has been removed." << endl;
}

int main() {
    vector<string> tasks;
    int choice = 0;

    while (true) {
        cout << "============================" << endl;
        cout << "     TO-DO LIST MENU" << endl;
        cout << "============================" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";

        if (!(cin >> choice)) {
            cout << "Invalid choice." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // clear newline before getline in addTask
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            addTask(tasks);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            viewTasks(tasks);
            deleteTask(tasks);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter 1-4." << endl;
        }
    }

    return 0;
}

