#include <iostream>
#include <vector>
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
    cout << "\033[105m" << "Task: 4_1\n" << "\033[m";
}

template<typename T>
void printVector(const vector<T>& v) {
    cout << "My vector has " << v.size() << " of these elements: ";

    for (size_t i = 0; i < v.size(); ++i) {
        cout << "[" << i << "] -> " << v[i];
        if (i < v.size() - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}

template<typename T>
void printVectorToFile(const vector<T>& v, const string& filename) {
    ofstream ofs(filename);
    if (!ofs.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    ofs << "My vector has " << v.size() << " of these elements: ";

    for (size_t i = 0; i < v.size(); ++i) {
        ofs << "[" << i << "] -> " << v[i];
        if (i < v.size() - 1) {
            ofs << ", ";
        }
    }

    ofs << endl;
    ofs.close();
}

int main() {
    int color = 100;
    printStudentInfo();
    setConsoleTextColor(color);

    vector<int> myVector = { 12, 23, 34, 45, 56 };

    printVector(myVector);

    printVectorToFile(myVector, "output.txt");
    resetConsoleColor();
    return 0;
}
