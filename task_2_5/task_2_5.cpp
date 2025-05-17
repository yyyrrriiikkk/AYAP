#include <iostream>
#include <fstream>
#include <string>

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
	cout << "\033[105m" << "Task: 2_5\n" << "\033[m";
}

int main() {
    int color = 100;
    printStudentInfo();
    setConsoleTextColor(color);

    const string inputFile = "text.txt";
    ifstream inFile(inputFile);

    if (!inFile.is_open()) {
        cerr << "Error" << inputFile << endl;
        return 1; 
    }

    string wordToFind;
    cout << "Enter the word to search for: ";
    getline(cin, wordToFind); 

    string line;
    int count = 0;

    while (getline(inFile, line)) {
        size_t pos = line.find(wordToFind); 
        while (pos != string::npos) {
            count++; 
            pos = line.find(wordToFind, pos + 1);
        }
    }

    inFile.close();

    if (count > 0) {
        cout << "The word \"" << wordToFind << "\" was found " << count << " times." << endl;
    }
    else {
        cout << "The word \"" << wordToFind << "\" was not found in the file." << endl;
    }
    resetConsoleColor();
    return 0;
}
