#include <iostream>
#include <set>

using namespace std;

int main() {

    set<int> s1;
    set<int> s2 = {3,1,3,2,5}; // {1,2,3,5}
    set<int> s3(s2);

    set<int> numbers = {1,2,3,4,5};
    int targets[] = {3,7};

    for(int target: targets) {
        auto result = numbers.find(target);

        if(result != numbers.end()) {
            cout << "find: " << target << "value: " << *result;
        }
    }

    set<int> s = {1,3,2,1,5};
    s.insert(4); // {1,2,3,4,5}
    s.erase(2); // {1,3,4,5}

    auto i = s.find(4);
    if(i != s.end()) {
        s.erase(i);
    }

    return 0;
}