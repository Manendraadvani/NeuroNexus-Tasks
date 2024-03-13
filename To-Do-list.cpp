#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task>& tasks, int index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks, int index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "\nOptions:\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string description;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, description);
            addTask(tasks, description);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            int index;
            cout << "Enter index of task to mark as completed: ";
            cin >> index;
            markCompleted(tasks, index);
        } else if (choice == 4) {
            int index;
            cout << "Enter index of task to remove: ";
            cin >> index;
            removeTask(tasks, index);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}
