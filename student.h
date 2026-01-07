#ifndef STUDENT_MANAGEMENT_TOOL_STUDENT_H
#define STUDENT_MANAGEMENT_TOOL_STUDENT_H
#include <string>

class student {
public:
	long long id;       /* Using long long for large student IDs */
	double GPA;
	std::string name;
	student *next;

	/* Setters for student data */
	void getID(long long ID) { this->id = ID; }
	void getGPA(double score) { this->GPA = score; }
	void getName(std::string Name) { this->name = Name; }

	/* Add a new student node to the end of the linked list */
	void newStudent(student *&first, student *&endp) {
		if (first == NULL) {
			first = endp = this;
		} else {
			endp->next = this;
			endp = this;
		}
		this->next = NULL;
	}
};
#endif