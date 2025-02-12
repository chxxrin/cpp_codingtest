#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    auto num =42;
    cout << num << '\n';

    auto pi = 3.141592;
    cout << pi << '\n';

    auto greeting = string("Hello world");
    cout << greeting << '\n';

    vector<int> vec = {1,2,3,4,5};
    for(int num:vec) {
        cout << num << '\n'; 
    }

    map<string, int> fruitMap = {{"apple", 1}, {"banana", 2}, {"cherry",3}};
    for(const auto& pair: fruitMap) {
        cout << pair.first << ' ' << pair.second << '\n';
    }
    cout << '\n';

    set<string> fruitSet = {"apple", "banana", "cherry"};
    cout << "Set : ";
    for(const auto& fruit: fruitSet) {
        cout << fruit << '\n';
    }
    cout << '\n';
    return 0;
}