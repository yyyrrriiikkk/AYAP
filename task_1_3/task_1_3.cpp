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


string vigenereEncode(const string& text, const string& key) {
	string result;
	int keyIndex = 0;

	for (size_t i = 0; i < text.length(); ++i) {
		if (isalpha(text[i])) {
			char base = islower(text[i]) ? 'a' : 'A';
			int shift = tolower(key[keyIndex % key.length()]) - 'a';
			result += (text[i] - base + shift) % 26 + base;
			keyIndex++;
		}
		else {
			result += text[i];
		}
	}
	return result;
}

string vigenereDecode(const string& text, const string& key) {
	string result;
	int keyIndex = 0;

	for (size_t i = 0; i < text.length(); ++i) {
		if (isalpha(text[i])) {
			char base = islower(text[i]) ? 'a' : 'A';
			int shift = tolower(key[keyIndex % key.length()]) - 'a';
			result += (text[i] - base - shift + 26) % 26 + base;
			keyIndex++;
		}
		else {
			result += text[i];
		}
	}
	return result;
}

int main() {

	int color = 100;
	setConsoleTextColor(color);
	cout << "Welcome to Vigenere\n";
	resetConsoleColor();

	printStudentInfo();
	char continueProgram = 'y';

	while (continueProgram == 'y' || continueProgram == 'Y') {
		setConsoleTextColor(color);
		int choice;
		cout << "Select function:\n1. Encoding (Vigenere)\n2. Decoding (Vigenere)\n";
		cin >> choice;
		if (choice == 1) {
			string key;
			string text;
			cout << "Vvedi kluchevoye slovo: ";
			cin >> key;
			cin.ignore();
			cout << "Enter the stroky to analyze: ";
			getline(cin, text);
			if (key.length() != text.length()) {
				cout << "Error!!!: size of strok != mezhdy soboi!" << endl;
			}
			else {
				cout << "Rez: " << vigenereEncode(text, key) << endl;
			}

		}
		else if (choice == 2) {
			string key;
			string text;
			cout << "Vvedi kluchevoye slovo: ";
			cin >> key;
			cin.ignore();
			cout << "Enter the stroky to analyze: ";
			getline(cin, text);
			if (key.length() != text.length()) {
				cout << "Error!!!: size of strok != mezhdy soboi!" << endl;
			}
			else {
				cout << "Rez: " << vigenereDecode(text, key) << endl;
			}
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
