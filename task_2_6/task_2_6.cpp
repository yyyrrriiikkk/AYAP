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
	cout << "\033[105m" << "Task: 2_6\n" << "\033[m";
}

int main() {
    int color = 100;
    printStudentInfo();
    setConsoleTextColor(color);

    const string inputFile = "large_file.txt";
    ifstream inFile(inputFile);

   
    if (!inFile.is_open()) {
        cerr << "Error" << inputFile << endl;
        return 1;
    }

    int partSize;
    cout << "Enter the size of each part (in characters): ";
    cin >> partSize;

    if (partSize <= 0) {
        cerr << "Error" << endl;
        return 1;
    }

    string content;
    string line;

    while (getline(inFile, line)) {
        content += line + "\n";
    }

   
    inFile.close();

    int totalParts = (content.size() + partSize - 1) / partSize; 
    for (int i = 0; i < totalParts; ++i) {
        string part = content.substr(i * partSize, partSize);
        string partFileName = "part" + to_string(i + 1) + ".txt";

        ofstream outFile(partFileName);
        if (!outFile.is_open()) {
            cerr << "Error" << partFileName << endl;
            return 1;
        }

        outFile << part; 
        outFile.close(); 
    }

 
    cout << "Total number of files created: " << totalParts << endl;
    resetConsoleColor();
    return 0;
}
