#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec = {10,20,30,40,50};

    for(auto i = vec.begin(); i != vec.end();i++) {
        cout << *i << '\n';
    }
    cout << '\n';

    auto result = find(vec.begin(), vec.end(), 30);
    if(result != vec.end()) {
        cout << "found : " << *result << '\n';
    } else {
        cout << "not found" << '\n';
    }

    return 0;
}