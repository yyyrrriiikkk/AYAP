#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

void setConsoleTextColor(int color) {
	cout << "\033[" << color << "m";
}

void resetConsoleColor() {
	cout << "\033[m";
}
void printStudentInfo() {
	cout << "\033[105m" << "Student: ZARUBECKY YAROSLAV\n" << "\033[m";
	cout << "\033[105m" << "Group: M10-101BV-24\n" << "\033[m";
	cout << "\033[105m" << "Task: 1_3\n" << "\033[m";
}

int main() {

	int color = 100;
	setConsoleTextColor(color);
	cout << "Welcome to first task\n";
	resetConsoleColor();
	cout << "Welcome to first task\n";
	printStudentInfo();
	resetConsoleColor();

	return 0;
}