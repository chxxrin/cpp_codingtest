#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1,2,2,3,3,3,4,4,5,5,5};

    auto newEnd = unique(v.begin(), v.end());

    for(auto i = v.begin(); i != newEnd;i++) {
        cout << *i << ' ';
    }
    cout << '\n';

    cout << v.size() << '\n';
    return 0;
}