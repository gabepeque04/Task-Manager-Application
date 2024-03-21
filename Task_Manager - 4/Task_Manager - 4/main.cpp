#include "TaskManager.h"
#include <iostream>
#include <cstdlib>

int main() {
    std::vector<Task> tasks; // Create a vector to store Task objects.
    const std::string filename = "tasks.txt"; // Specify the filename for data persistence.
    UserAuthentication auth; // Initialize user authentication

    // User Authentication
    std::string username, password;
    std::cout << "Task Manager" << std::endl;
    std::cout << "Please login:" << std::endl;
    std::cout << "Username: ";
    std::getline(std::cin, username);
    std::cout << "Password: ";
    std::getline(std::cin, password);
    system("cls");
    if (!auth.authenticate(username, password)) {
        std::cout << "Invalid username or password. Exiting program." << std::endl;
        return 1;
    }

    // Load tasks from file at the start.
    loadTasks(tasks, filename);

    // Task Manager Menu
    int choice;
    while (true) {
        std::cout << "\nTask Manager Menu: " << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. List Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Save Tasks" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice; // Read the user's choice
        std::cin.ignore(); // Clear the input buffer
        system("cls");
        switch (choice) {
        case 1:
            addTask(tasks); // Call the function to add a new task
            break;
        case 2:
            listTasks(tasks); // Call the function to list all tasks
            break;
        case 3:
            markTaskCompleted(tasks); // Call the function to mark a task as completed
            break;
        case 4:
            saveTasks(tasks, filename); // Call the function to save tasks to a file
            break;
        case 5:
            // Save tasks to file before exiting
            saveTasks(tasks, filename);
            std::cout << "Exiting program. Goodbye!" << std::endl; // Display exit message
            return 0; // Return from main function to exit the program
        default:
            std::cout << "Invalid choice. Please try again." << std::endl; // Display error message for invalid input
        }
    }

    return 0; // Ensure that the function returns an integer
}
