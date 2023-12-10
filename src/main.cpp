#include "ToDoList.h"
#include <string>
int main() {
    ToDoList toDoList;
    
    int selection;
    do {
        cout << "Welcome to the To-Do List!" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Mark task as completed" << endl; 
        cout << "4. Delete task" << endl;
        cout << "5. Save task" << endl;
        cout << "6. Load task" << endl;
        cout << "0. Exit" << endl;
        cout << "Please enter your selection: ";
        cin >> selection;

        switch(selection) {
            case 1: {
                string title, description;
                cout << "Enter task title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter task description: ";
                getline(cin, description);
                toDoList.addTask(title, description);
                break;
            }

            case 2: {
                toDoList.viewTasks();
                break;
            }

            case 3: {
                int taskIndex;
                cout << "Enter the task index: "; 
                cin >> taskIndex;
                toDoList.markTaskAsCompleted(taskIndex - 1);
                break;
            }
            
            case 4: {
                int taskIndex;
                cout << "Enter the task index: "; 
                cin >> taskIndex;
                toDoList.deleteTask(taskIndex - 1);
                break;
            }

            case 5: {
                string fileName;
                cout << "Enter the file name to save task: ";
                cin >> fileName;
                toDoList.saveTasksToFile(fileName);
                break;
            }

            case 6: {
                string fileName;
                cout << "Enter the file name to load task from: ";
                cin >> fileName;
                toDoList.loadTasksFromFile(fileName);
                break;
            }
            
            case 0:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid selection." << endl;
                break;
        }
    } while(selection != 0);

    return 0;
}
