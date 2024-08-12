// #10871 : X보다 작은수 
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, t;

    cin >> n >> x;

    // n개를 다 돌때까지 반복
    while(n--) {
        cin >> t; 
        if(t < x) {
            cout << t << ' ';
        }
    }
}