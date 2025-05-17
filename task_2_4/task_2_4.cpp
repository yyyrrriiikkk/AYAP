#include <iostream>
#include <fstream>

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
	cout << "\033[105m" << "Task: 2_4\n" << "\033[m";
}

int main() {
    int color = 100;
    printStudentInfo();
    setConsoleTextColor(color);

    const string inputFile = "text.txt";
    ifstream inFile(inputFile);

    if (!inFile.is_open()) {
        cerr << "Error " << inputFile << endl;
        return 1; 
    }

    char ch;
    int charCount = 0;

    while (inFile.get(ch)) { 
        charCount++; 
    }


    inFile.close();

    cout << "Total number of symbols " << inputFile << ": " << charCount << endl;
    resetConsoleColor();
    return 0;
}
