#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, double> employeeSalaries;

map<string, double> studentGrades = {
    {"John", 3.7},
    {"Emma", 3.9},
    {"Sophia", 4.0}
};

int main() {
    map<string, int> studentScores;

    studentScores["Alice"] = 95;
    studentScores["Bob"] = 88;
    studentScores["Charlie"] = 92;

    int score1 = studentScores["Alice"];
    cout << score1 << '\n';

    int score2 = studentScores["rabbit"];
    cout << score2 << '\n';

    auto i = studentScores.find("Charlie");
    if(i != studentScores.end()) {
        int score3 = i -> second;
        cout << score3 << '\n';
    }

    map<string, int> myMap = {{"Apple", 1}, {"Banana", 2}, {"Cherry", 3}};
    myMap["Banana"] = 10;

    return 0;

    map<int, string> myMap2;

    myMap2.insert(make_pair(1, "Apple"));
    myMap2.insert({2, "Banana"});
    myMap2[3] = "Cherry";

    for (const auto& pair : myMap2) {
        cout << pair.first << ": " << pair.second << '\n';
    }

    myMap2.erase(2);
    for(const auto& pair : myMap2) {
        cout << pair.first << ": " << pair.second << '\n';
    }

    auto i2 = myMap2.find(3);
    if(i2 != myMap2.end()) {
        myMap2.erase(i2);
    }

    for(const auto& pair: myMap2) {
        cout << pair.first << ": " << pair.second << '\n';
    }
}

