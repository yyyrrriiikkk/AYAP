#include <iostream>
#include <map>
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
    cout << "\033[105m" << "Task: 4_4\n" << "\033[m";
}

template<typename K, typename V>
void printMap(const map<K, V>& m) {
    cout << "My map has " << m.size() << " of keys and has these pairs: ";

    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << "[" << it->first << "] -> {" << it->second << "}";
        if (next(it) != m.end()) {
            cout << ", "; 
        }
    }

    cout << endl;
}

template<typename K, typename V>
void printMapToFile(const map<K, V>& m, const string& filename) {
    ofstream ofs(filename);
    if (!ofs.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    ofs << "My map has " << m.size() << " of keys and has these pairs: ";

    for (auto it = m.begin(); it != m.end(); ++it) {
        ofs << "[" << it->first << "] -> {" << it->second << "}";
        if (next(it) != m.end()) {
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

    map<int, string> myMap = {
        {10, "MAI"},
        {1, "Ulybin"},
        {6, "AYAP"}
    };

    printMap(myMap);

    printMapToFile(myMap, "output.txt");
    resetConsoleColor();
    return 0;
}