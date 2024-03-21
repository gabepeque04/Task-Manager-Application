#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <string>
#include <unordered_map>

// Struct to represent a task with title, completion status, priority, category, and due date.
struct Task {
    std::string title;      // Title or description of the task.
    bool completed;         // Indicates whether the task is completed (true) or not (false).
    int priority;           // Priority of the task (1 for low, 2 for medium, 3 for high).
    std::string category;   // Category of the task.
    std::string dueDate;    // Due date of the task (in DD-MM-YYYY format).
};

// User Authentication Class
class UserAuthentication {
private:
    std::unordered_map<std::string, std::string> credentials; // Store username and hashed password

    // Hash function for passwords (dummy implementation for demonstration)
    std::string hashPassword(const std::string& password);

public:
    UserAuthentication();

    // Check if the provided username and password match
    bool authenticate(const std::string& username, const std::string& password);
};

// Function to validate a date string in DD-MM-YYYY format using regular expressions.
bool isValidDate(const std::string& date);

// Function to add a new task to the task manager application.
void addTask(std::vector<Task>& tasks);

// Function to display the list of tasks.
void listTasks(const std::vector<Task>& tasks);

// Function to mark a task as completed.
void markTaskCompleted(std::vector<Task>& tasks);

// Function to save tasks to a file.
void saveTasks(const std::vector<Task>& tasks, const std::string& filename);

// Function to load tasks.
void loadTasks(std::vector<Task>& tasks, const std::string& filename);

#endif // TASK_MANAGER_H
