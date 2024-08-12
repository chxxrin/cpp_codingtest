#include <iostream>
#include <algorithm>

using namespace std;

int func4(int N) {
    int val = 1;
    while(2*val <= N) {
        val *= 2;
    }
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

}