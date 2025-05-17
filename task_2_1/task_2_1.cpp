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
	cout << "\033[105m" << "Task: 2_1\n" << "\033[m";
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

void encryptFile(const string& inputFile, const string& outputFile, int a) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        outFile << caesarEncode(line, a) << endl;
    }

    inFile.close();
    outFile.close();
}

void decryptFile(const string& inputFile, const string& outputFile, int a) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        outFile << caesarDecode(line, a) << endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    int color = 100;
    setConsoleTextColor(color);
    cout << "Welcome to Caesar\n";
    resetConsoleColor();

    printStudentInfo();
    setConsoleTextColor(color);

    int a;
    cout << "Enter offset: ";
    cin >> a;
    cin.ignore(); 
    encryptFile("input.txt", "encrypted.txt", a);
    cout << "Encryption complete. Encrypted text saved to 'encrypted.txt'." << endl;

    decryptFile("encrypted.txt", "decrypted.txt", a);
    cout << "Decryption complete. Decrypted text saved to 'decrypted.txt'." << endl;
    resetConsoleColor();
    return 0;
}
