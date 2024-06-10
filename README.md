# Task Manager Application

Welcome to the Task Manager Application! This project is designed to help users manage their tasks effectively, with features such as task creation, listing, marking tasks as completed, and saving/loading tasks from a file. User authentication is also included to ensure secure access.
## Features

- User Authentication: Simple login system to protect access to the task manager.
- Task Management: Add, list, and mark tasks as completed.
- Task Persistence: Save tasks to a file and load them on startup.
- Task Details: Each task includes a title, category, due date, priority, and completion status.
- User-Friendly Interface: Clear console-based menu for easy navigation.
## Getting Started

- C++ Compiler: Ensure you have a C++ compiler installed (e.g., g++, clang++).
- C++ Standard Library: Make sure you have access to the C++ Standard Library.
## Menu options

1. Add Task: Enter task details including title, category, due date, and priority.
2. List Tasks: Display all tasks with their details.
3. Mark Task as Completed: Select a task to mark it as completed.
4. Save Tasks: Save all tasks to a file for persistence.
5. Exit: Save tasks and exit the application.
## Task Fields

- Title: Short description of the task.
- Category: Category or group the task belongs to.
- Due Date: Due date of the task in DD-MM-YYYY format.
- Priority: Priority level of the task (1 for Low, 2 for Medium, 3 for High).
- Completion Status: Indicates whether the task is completed or not.
## Code Structure

- main.cpp: Contains the main function and the task manager menu logic.
- TaskManager.h: Header file declaring the Task struct, UserAuthentication class, and task-related functions.
- TaskManager.cpp: Implementation of the task-related functions and user authentication logic.





