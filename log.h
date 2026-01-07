#ifndef STUDENT_MANAGEMENT_TOOL_LOG_H
#define STUDENT_MANAGEMENT_TOOL_LOG_H
#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

/* Helper to get formatted current time */
inline std::string getTime() {
	time_t now = time(0);
	std::string dt = ctime(&now);
	if (!dt.empty() && dt[dt.length() - 1] == '\n')
		dt.erase(dt.length() - 1); /* Remove trailing newline from ctime */
	return dt;
}

struct logNode {
	std::string action;
	std::string time;
	logNode *next;
};

class history {
private:
	logNode *top; /* Pointer to the top of the stack */
public:
	history() { top = NULL; }

	/* Push a new action onto the history stack */
	void push(std::string msg) {
		logNode *p = new logNode;
		p->action = msg;
		p->time = getTime();
		p->next = top;
		top = p;
	}

	/* Display recent activities in LIFO order */
	void show() {
		logNode *temp = top;
		int i = 1;
		std::cout << "\n~~ Recent Activity ~~" << std::endl;
		if (temp == NULL) std::cout << "No logs found." << std::endl;

		while (temp != NULL && i <= 10) {
			std::cout << i << ") " << std::left << std::setw(15) << temp->action
					  << " | Time: " << temp->time << std::endl;
			temp = temp->next;
			i++;
		}
	}
};
#endif