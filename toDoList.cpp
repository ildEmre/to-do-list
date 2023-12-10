#include "ToDoList.h"
#include <string>
void ToDoList::addTask(string title, string description) {
    Task newTask = {title, description, false};
    tasks.push_back(newTask);
}

void ToDoList::viewTasks() {
    if(tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "Tasks: " << endl;
        for(size_t i = 0; i < tasks.size(); i++) {
            cout << "[" << i + 1 << "]";
            cout << "Title: " << tasks[i].title << " | ";
            cout << "Description: " << tasks[i].description << " | ";
            cout << (tasks[i].completed ? "Completed" : "Not Completed") << endl;
        }
    }
}

void ToDoList::markTaskAsCompleted(int taskIndex) {
    if(taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks[taskIndex].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void ToDoList::deleteTask(int taskIndex) {
    if(taskIndex >=0 && taskIndex < tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex);
        cout << "Task successfully deleted" << endl;
    } else {
        cout << "Invalid task index" << endl;
    }
}

void ToDoList::saveTasksToFile(string fileName) {
    ofstream outFile;
    outFile.open(fileName);
    if(!outFile.is_open()) {
        cerr << "Unable to open file. " << endl;
    } else {
        for(const auto& task : tasks) {
            outFile << task.title << "," << task.description << "," << task.completed << endl;
        }
    }
}

void ToDoList::loadTasksFromFile(string fileName) {
    ifstream inFile;
    inFile.open(fileName);
    if(!inFile.is_open()) {
        cerr << "Unable to open file." << endl;
    } else {
        tasks.clear();
        string line;
        while(getline(inFile, line)) {
            Task task;
            size_t commaPos = line.find(',');
            task.title = line.substr(0, commaPos);
            line = line.substr(commaPos + 1);
            commaPos = line.find(',');
            task.description = line.substr(0, commaPos);
            line = line.substr(commaPos + 1);
            task.completed = (line == "1");
            tasks.push_back(task);
        }
    }
}
