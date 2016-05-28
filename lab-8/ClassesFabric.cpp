#include <map>
#include <functional>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Base {
private:
	int value;
public:
	Base() : value(0) {}
	Base(int val) : value(val) {}
	virtual void show() = 0;
	int get() { return value; }

};

class A : public Base {
public:
	A() : Base() {}
	A(int val) : Base(val) {}
	void show() {
		cout << "class A: " << get() << endl;
	}
};

class B : public Base {
public:
	B() : Base() {}
	B(int val) : Base(val) {}
	void show() {
		cout << "class B: " << get() << endl;
	}
};

class C : public Base {
public:
	C() : Base() {}
	C(int val) : Base(val) {}
	void show() {
		cout << "class C: " << get() << endl;
	}
};

vector<string> &split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

void showAll(vector<A> classA, vector<B> classB, vector<C> classC) {
	for (auto it : classA) {
		it.show();
	}
	for (auto it : classB) {
		it.show();
	}
	for (auto it : classC) {
		it.show();
	}
}

int main() {
	size_t N, size;
	string command;
	vector<string> commands;
	vector<A> classA;
	vector<B> classB;
	vector<C> classC;
	cin >> N;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (size_t i = 0; i < N; i++) {
		getline(cin, command);
		commands = split(command, ' ');
		size = commands.size();
		if (size == 3) {
			if (commands[0] == "create") {
				if (commands[1] == "A") {
					A obj(stoi(commands[2]));
					classA.push_back(obj);
				}
				else if (commands[1] == "B") {
					B obj(stoi(commands[2]));
					classB.push_back(obj);
				}
				else if (commands[1] == "C") {
					C obj(stoi(commands[2]));
					classC.push_back(obj);
				}
				else {
					cout << "Incorrect command. Try again.\n";
					i--;
				}
			}
			else {
				cout << "Incorrect command. Try again.\n";
				i--;
			}
		}
		else if (size == 1) {
			if (commands[0] == "showall") {
				showAll(classA, classB, classC);
			}
			else {
				cout << "Incorrect command. Try again.\n";
				i--;
			}
		}
		else {
			cout << "Incorrect command. Try again.\n";
			i--;
		}
	}

	//showAll(classA, classB, classC);
	system("pause");
	return 0;
}
