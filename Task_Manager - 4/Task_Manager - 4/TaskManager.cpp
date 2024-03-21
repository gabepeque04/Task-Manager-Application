#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <regex>

std::string UserAuthentication::hashPassword(const std::string& password) {
    // Replace with a proper hash function (e.g., bcrypt) for secure password hashing in a real application
    return password;
}

UserAuthentication::UserAuthentication() {
    // Initialize with default username and password
    credentials["user"] = hashPassword("password");
}

bool UserAuthentication::authenticate(const std::string& username, const std::string& password) {
    auto it = credentials.find(username);
    if (it != credentials.end()) {
        return it->second == hashPassword(password);
    }
    return false;
}

bool isValidDate(const std::string& date) {
    std::regex pattern("\\d{2}-\\d{2}-\\d{4}"); // Regular expression pattern for DD-MM-YYYY format
    return std::regex_match(date, pattern);
}

void addTask(std::vector<Task>& tasks) {
    Task newTask;

    std::cout << "Enter task title: ";
    std::getline(std::cin, newTask.title);

    std::cout << "Enter task category: ";
    std::getline(std::cin, newTask.category);

    std::string dueDate;
    do {
        std::cout << "Enter task due date (DD-MM-YYYY): ";
        std::getline(std::cin, dueDate);
        if (!isValidDate(dueDate)) {
            std::cout << "Invalid date format! Please enter date in DD-MM-YYYY format." << std::endl;
        }
    } while (!isValidDate(dueDate));
    newTask.dueDate = dueDate;

    do {
        std::cout << "Enter task priority (1 - Low, 2 - Medium, 3 - High): ";
        std::cin >> newTask.priority;
        std::cin.ignore(); // Clear input buffer.

        if (newTask.priority < 1 || newTask.priority > 3) {
            std::cout << "Invalid priority level! Please enter 1, 2, or 3." << std::endl;
        }
    } while (newTask.priority < 1 || newTask.priority > 3);

    newTask.completed = false;

    tasks.push_back(newTask);

    std::cout << "Task added successfully!" << std::endl;
}

void listTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks found." << std::endl;
        return;
    }

    std::cout << "Task List: " << std::endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        const Task& task = tasks[i];

        std::cout << i + 1 << ". " << task.title << " [Category: " << task.category << "] [Due: " << task.dueDate << "] = Priority: ";

        switch (task.priority) {
        case 1:
            std::cout << "Low";
            break;
        case 2:
            std::cout << "Medium";
            break;
        case 3:
            std::cout << "High";
            break;
        default:
            std::cout << "Unknown";
        }

        std::cout << " - " << (task.completed ? "Completed" : "Incomplete") << std::endl;
    }
}

void markTaskCompleted(std::vector<Task>& tasks) {
    listTasks(tasks);

    std::cout << "Enter the index of the task to mark as completed: ";
    int index;
    std::cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        std::cout << "Task marked as completed!" << std::endl;
    }
    else {
        std::cout << "Invalid task index!" << std::endl;
    }
}

void saveTasks(const std::vector<Task>& tasks, const std::string& filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (const Task& task : tasks) {
            file << task.title << "," << task.category << "," << task.dueDate << "," << task.completed << "," << task.priority << std::endl;
        }
        file.close();
        std::cout << "Tasks saved to file: " << filename << std::endl;
    }
    else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

void loadTasks(std::vector<Task>& tasks, const std::string& filename) {
    tasks.clear(); // Clear existing tasks.
    std::ifstream file(filename); // Creates an input file stream 'file' and opens the file specified by the 'filename' string.
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            Task task;
            size_t pos = line.find(",");
            task.title = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            task.category = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            task.dueDate = line.substr(0, pos);
            line.erase(0, pos + 1);

            task.completed = line[0] - '0';
            line.erase(0, 2);
            task.priority = std::stoi(line);
            tasks.push_back(task);
        }
        file.close();
        std::cout << "Tasks loaded from file: " << filename << std::endl;
    }
    else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
}

