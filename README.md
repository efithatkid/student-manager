# Student Management System

A robust and efficient student record management application developed for the **Amol University of Special Modern Technologies (AUSMT)**. This project demonstrates the practical implementation of fundamental data structures in **C++** without relying on high-level libraries (No STL), focusing on manual memory management and pointer logic.

## Institutional Information
* **University:** Amol University of Special Modern Technologies (AUSMT)
* **Project Type:** Final Project for Data Structures

## Key Features

* **Dynamic Registry:** Uses a **Singly Linked List** to store student records (ID, Name, GPA). Students are appended to the end of the list to maintain order.
* **Activity Logging:** Implements a **Linked Stack** (LIFO) to track system actions like registrations and removals.
* **History with Timestamps:** Automatically captures the exact time of each operation using the `<ctime>` library.
* **Input Validation:** Robust error handling for student IDs (using `long long`) and GPA inputs to prevent buffer overflows or program crashes.
* **Full CRUD Operations:** Supports adding, deleting, searching, and listing all student records.

## Technical Architecture

### Data Structures
1.  **Linked List:** The primary structure for storing student data, optimized for dynamic growth.
2.  **Stack:** A secondary structure used for the "History" feature, ensuring the most recent activity is displayed first.

### File Structure
* `student.h`: Defines the `student` class and linked list node management.
* `log.h`: Contains the `history` class and logic for the stack-based logger.
* `main.cpp`: The driver code containing the user interface and main execution loop.

## 💻 Compilation and Usage

### Prerequisites
* A C++ compiler (e.g., GCC/G++, Clang, or MSVC).

### Execution
To compile and run the project using G++:

```bash
g++ main.cpp -o StudentManager
./StudentManager
