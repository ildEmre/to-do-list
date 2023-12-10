#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Task {
    string title;
    string description;
    bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(string title, string description);
    void viewTasks();
    void markTaskAsCompleted(int taskIndex);
    void deleteTask(int taskIndex);
    void saveTasksToFile(string fileName);
    void loadTasksFromFile(string fileName);
};

#endif // TODO_LIST_H
