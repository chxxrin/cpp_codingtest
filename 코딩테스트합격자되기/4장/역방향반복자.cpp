#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {10,20,30,40,50};

    for(auto i = vec.rbegin(); i != vec.rend() ; i++ ){
        cout << *i << '\n';
    }
    cout << '\n';

    auto result = find(vec.rbegin(), vec.rend(), 30);
    if(result != vec.rend()) {
        cout << "found : " << *result << '\n';
    } else {
        cout << "not found" << '\n';
    }


    return 0;
}