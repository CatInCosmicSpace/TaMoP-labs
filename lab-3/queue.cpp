#include <iostream>
#include <string>
using namespace std;

/**
	\class Class of move
*/
class Queue {
public:
	Queue(int _data) : data(_data), next(nullptr) {};
	~Queue() {};

	int		data;
	Queue	*next;
};

class QueueController {
public:
	QueueController() : head(nullptr), tail(nullptr) {};
	~QueueController() {};

	Queue	*head;
	Queue	*tail;
	
	/// \fn Adding element
	void	add(int data) {
		Queue *newElement = new Queue(data);
		if (tail != nullptr) {
			tail->next = newElement;
			tail = tail->next;
		}
		else
			head = tail = newElement;
		return;
	};

	/// \fn Deleting element
	void	del(void) {
		if (head != nullptr) {
			Queue *deleted = head;
			head = head->next;
			delete deleted;
		}
		else
			tail = nullptr;
		return;
	};
	
	/// \fn Getting element
	int	get(void) {
		return head->data;
	};
};

/**
	\fn Main function of application
*/
int main() {
	size_t n;       ///Number of commands
	string line;    ///Command name
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		cin >> line;
		if (line == "add") {
			cin >> line;
			Move.push(line);
		}
		else if (line == "get")
			Move.get();
		else if (line == "del")
			Move.pop();
		else
			return 1;

	}

	return 0;
}
