#include <iostream>
#include <vector>
#include <sstream>
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
    cout << "\033[105m" << "Task: 4_3\n" << "\033[m";
}

vector<int>& operator>>(istream& is, vector<int>& vec) {
    string line;
    getline(is, line); // Считываем всю строку

    // Заменяем разделители на пробелы
    for (char& ch : line) {
        if (ch == ',' || ch == ';') {
            ch = ' ';
        }
    }

    // Используем stringstream для разбора строки
    stringstream ss(line);
    int number;

    // Читаем числа из строки
    while (ss >> number) {
        vec.push_back(number);
        // Пропускаем пробелы между числами
        if (ss.peek() == ' ') {
            ss.ignore();
        }
    }

    return vec;
}

int main() {
    int color = 100;
    printStudentInfo();
    setConsoleTextColor(color);

    vector<int> numbers;

    cout << "Enter numbers separated by space, comma or semicolon: ";

    cin >> numbers; // Вводим данные в вектор

    cout << "You entered: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    cout << endl;
    resetConsoleColor();
    return 0;
}
