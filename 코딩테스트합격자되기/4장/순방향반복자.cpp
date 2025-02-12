#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> myMap = {{"apple", 1}, {"banana", 2} , {"cherry",3}};

    for(auto i = myMap.begin() ; i != myMap.end() ; i++ ) {
        cout << i->first << ' ' << i->second << '\n';
    }

    auto result = myMap.find("banana");
    if(result != myMap.end()) {
        cout << "found: " << result->first << "->" << result->second << '\n';
    } else {
        cout << "not found" << '\n';
    }


    return 0;
}