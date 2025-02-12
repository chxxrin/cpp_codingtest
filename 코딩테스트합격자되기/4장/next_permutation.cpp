#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v = {3,1,2};
    sort(v.begin(), v.end());

    do {
        for (int i: v) {
            cout << i << ' ';
        }
        cout << '\n';
    } while(next_permutation(v.begin(), v.end()));
    return 0;
}