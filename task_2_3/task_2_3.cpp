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
	cout << "\033[105m" << "Task: 2_3\n" << "\033[m";
}

void replaceWordInFile(const string& inputFile, const string& outputFile, const string& oldWord, const string& newWord) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open()) {
        cerr << "Error" << inputFile << endl;
        return;
    }
    if (!outFile.is_open()) {
        cerr << "Error" << outputFile << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {

        size_t pos = 0;
        while ((pos = line.find(oldWord, pos)) != string::npos) {
            line.replace(pos, oldWord.length(), newWord);
            pos += newWord.length(); 
        }
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    cout << "Word replacement completed. Modified text file: " << outputFile << endl;
}

int main() {
    int color = 100;
    printStudentInfo();
    setConsoleTextColor(color);

    const string inputFile = "text.txt";
    const string outputFile = "modified.txt";
    string oldWord, newWord;

    cout << "Enter the word to be replaced: ";
    getline(cin, oldWord);
    cout << "Enter the new word: ";
    getline(cin, newWord);

    replaceWordInFile(inputFile, outputFile, oldWord, newWord);
    resetConsoleColor();
    return 0;
}