#include <iostream>
#include <limits>
#include "student.h"
#include "log.h"

using namespace std;

/* Function to remove a student by ID from the linked list */
bool deleteStudent(student *&first, student *&endp, long long target) {
    student *prevp = NULL, *p = first;
    while (p != NULL) {
        if (p->id == target) {
            if (prevp == NULL) first = p->next;
            else prevp->next = p->next;

            if (p == endp) endp = prevp;
            delete p;
            return true;
        }
        prevp = p;
        p = p->next;
    }
    return false;
}

/* Handle student registration flow */
void registerFlow(student *&first, student *&endp, history *log) {
    long long id;
    double gpa;
    string name;

    cout << "Enter student id: ";
    while (!(cin >> id)) {
        cout << "Invalid ID! Enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter GPA: ";
    while (!(cin >> gpa)) {
        cout << "Invalid GPA! Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter your name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); /* Flush buffer before getline */
    getline(cin, name);

    student *stu = new student;
    stu->getID(id);
    stu->getGPA(gpa);
    stu->getName(name);
    stu->newStudent(first, endp);

    log->push("Register: " + name);
    cout << "Registration process completed successfully! \n";
}

/* Handle student removal flow */
void removeFlow(student *&first, student *&endp, history *log) {
    long long input;
    cout << "Enter student ID to remove: ";
    cin >> input;
    if (deleteStudent(first, endp, input)) {
        cout << "Operation succeeded \n";
        log->push("Remove ID: " + to_string(input));
    } else {
        cout << "Operation failed: Student not found. \n";
    }
}

/* List all registered students */
void listStudents(student *first) {
    student *p = first;
    int i = 1;
    if (p == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    cout << "\n--- Student List ---" << endl;
    while (p != NULL) {
        cout << i << ") ID: " << p->id << " | Name: " << p->name << " | GPA: " << p->GPA << endl;
        p = p->next;
        i++;
    }
}

/* Search for a student by ID */
void search(student *first) {
    long long target;
    cout << "Enter student ID to search: ";
    cin >> target;
    student *p = first;
    while (p != NULL) {
        if (p->id == target) {
            cout << "Match found!\nName: " << p->name << "\nGPA: " << p->GPA << "\nID: " << p->id << endl;
            return;
        }
        p = p->next;
    }
    cout << "No match found.\n";
}

int main() {
    string choice;
    student *first = NULL;
    student *endp = NULL;
    history logSystem;

    while (true) {
        cout << "\n~~ Student Manager App ~~\n";
        cout << "1) Register\n2) Remove\n3) Search\n4) History\n5) List All\n-1) Exit\nSelection: ";
        cin >> choice;

        try {
            int op = stoi(choice);
            switch (op) {
                case 1: registerFlow(first, endp, &logSystem); break;
                case 2: removeFlow(first, endp, &logSystem); break;
                case 3: search(first); break;
                case 4: logSystem.show(); break;
                case 5: listStudents(first); break;
                case -1: exit(0);
                default: cout << "Invalid selection!" << endl;
            }
        } catch (...) {
            cout << "Please enter a valid numeric option." << endl;
        }
    }
    return 0;
}