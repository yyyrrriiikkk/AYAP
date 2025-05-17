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
    cout << "\033[105m" << "Student: ZARUBECKY YAROSLAVR\n" << "\033[m";
    cout << "\033[105m" << "Group: M10-101BV-24\n" << "\033[m";
    cout << "\033[105m" << "Task: 4_2\n" << "\033[m";
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

template<typename T>
vector<T> operator+(const vector<T>& lhs, const vector<T>& rhs) {
    vector<T> result(lhs);
    result.insert(result.end(), rhs.begin(), rhs.end());
    return result;
}

int main() {
    int color = 100;
    printStudentInfo();
    setConsoleTextColor(color);



    vector<int> vec1 = { 12, 23, 34 };
    vector<int> vec2 = { 45, 56 };
    printVector(vec1);
    printVector(vec2);
    vector<int> combinedVec = vec1 + vec2;

    printVector(combinedVec);


    printVectorToFile(combinedVec, "output.txt");
    resetConsoleColor();
    return 0;
}
