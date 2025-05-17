#include <iostream>
#include <map>
#include <string>
#include <cstdlib> 
#include <ctime>   

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
    cout << "\033[105m" << "Task: 3_3\n" << "\033[m";
}


int countPlayersAboveScore(const map<string, int>& players, const int minScore) {
    int count = 0;
    for (const auto& player : players) {
        if (player.second > minScore) {
            count++;
        }
    }
    return count;
}

int main() {
    int color = 100;
    printStudentInfo();
    setConsoleTextColor(color);

    map<string, int> players;
    string playerName;

    srand(static_cast<unsigned int>(time(0)));

    cout << "Enter player names (type 'exit' to finish):" << endl;

    while (true) {
        cout << "Player name: ";
        getline(cin, playerName);

        if (playerName == "exit") {
            break;
        }

        int score = rand() % 99 + 1;

        players[playerName] = score;
    }

    cout << "\nPlayers and their scores:" << endl;
    for (const auto& player : players) {
        cout << player.first << ": " << player.second << " points" << endl;
    }

    int minScore;
    cout << "\nEnter minimum score to count players above: ";
    cin >> minScore;

    int count = countPlayersAboveScore(players, minScore);
    cout << "Number of players with scores above " << minScore << ": " << count << endl;
    resetConsoleColor();
    return 0;
}