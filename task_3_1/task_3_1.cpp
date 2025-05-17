#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>
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
    cout << "\033[105m" << "Task: 3_1\n" << "\033[m";
}



void printStdMap(const vector<pair<string, int>>& par_map) {
    for (const auto& pair : par_map) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }
}

void printVectoredMap(const vector<pair<string, vector<int>>>& par_map) {
    for (const auto& pair : par_map) {
        cout << "Key: " << pair.first << ", Values: ";
        for (const int& value : pair.second) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    int color = 100;
    printStudentInfo();
    setConsoleTextColor(color);


    vector<pair<string, int>> map1 = { {"one", 1}, {"two", 2} };
    vector<pair<string, vector<int>>> map2 = {
        {"numbers", {1, 2, 3}},
        {"primes", {31, 47, 59}}
    };

    printStdMap(map1);
    printVectoredMap(map2);
    resetConsoleColor();

    return 0;
}
