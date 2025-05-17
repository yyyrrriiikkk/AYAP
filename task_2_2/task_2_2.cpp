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
	cout << "\033[105m" << "Task: 2_2\n" << "\033[m";
}

void mergeFiles(const string& file1, const string& file2, const string& outputFile) {
    ifstream inFile1(file1);
    ifstream inFile2(file2);
    ofstream outFile(outputFile);

    if (!inFile1.is_open()) {
        cerr << "Error" << file1 << endl;
        return;
    }
    if (!inFile2.is_open()) {
        cerr << "Error" << file2 << endl;
        return;
    }

    string line;
    while (getline(inFile1, line)) {
        outFile << line << endl;
    }
    while (getline(inFile2, line)) {
        outFile << line << endl;
    }

    inFile1.close();
    inFile2.close();
    outFile.close();

    cout << "Files merged successfully into " << outputFile << endl;
}

int main() {
    int color = 100;
    printStudentInfo();
    setConsoleTextColor(color);

    const string file1 = "file1.txt";
    const string file2 = "file2.txt";
    const string outputFile = "merged.txt";

    mergeFiles(file1, file2, outputFile);
    resetConsoleColor();
    return 0;
}
