#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
void displayMenu();
void addTask(vector<string> &tasks);
void viewTasks(const vector<string> &tasks);
void deleteTask(vector<string> &tasks);

int main()
{
    vector<string> tasks;
    int choice;

    while (true)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after entering the choice

        switch (choice)
        {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            deleteTask(tasks);
            break;
        case 4:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}

void displayMenu()
{
    cout << "\nTo-Do List Menu:" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Exit" << endl;
}

void addTask(vector<string> &tasks)
{
    string task;
    cout << "Enter the task description: ";
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully." << endl;
}

void viewTasks(const vector<string> &tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks to display." << endl;
    }
    else
    {
        cout << "\nCurrent Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

void deleteTask(vector<string> &tasks)
{
    viewTasks(tasks);
    if (!tasks.empty())
    {
        int index;
        cout << "Enter the number of the task to delete: ";
        cin >> index;
        cin.ignore(); // To ignore the newline character after entering the index

        if (index > 0 && index <= static_cast<int>(tasks.size()))
        {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task deleted successfully." << endl;
        }
        else
        {
            cout << "Invalid task number. Please try again." << endl;
        }
    }
}