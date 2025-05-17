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
	cout << "\033[105m" << "Task: 1_2\n" << "\033[m";
}



string caesarEncode(const string& text, int a) {
	string result;
	for (char c : text) {
		if (isalpha(c)) {
			char base = islower(c) ? 'a' : 'A';
			result += (c - base + a) % 26 + base;
		}
		else {
			result += c;
		}
	}
	return result;
}


string caesarDecode(const string& text, int a) {
	return caesarEncode(text, 26 - (a % 26));
}


int main() {

	int color = 100;
	setConsoleTextColor(color);
	cout << "Welcome to Caesar\n";
	resetConsoleColor();

	printStudentInfo();
	char continueProgram = 'y';

	while (continueProgram == 'y' || continueProgram == 'Y') {
		setConsoleTextColor(color);
		int choice;
		cout << "Select function:\n1. Encoding (Caesar)\n2. Decoding (Caesar)\n";
		cin >> choice;


		if (choice == 1) {
			int shift;
			string text;
			cout << "Enter offset: ";
			cin >> shift;
			cout << "Enter string to analyze: ";
			getline(cin, text);
			cout << "Rez: " << caesarEncode(text, shift) << endl;

		}
		else if (choice == 2) {
			int shift;
			string text;
			cout << "Enter offset: ";
			cin >> shift;
			cout << "Enter string to analyze: ";
			getline(cin, text);
			cout << "Rez: " << caesarDecode(text, shift) << endl;

		}

		else {
			cout << "False vbIbor)))))." << endl;
		}
		cout << "Prodolgim? (y/n): ";
		cin >> continueProgram;
	}
	resetConsoleColor();
	return 0;
}
