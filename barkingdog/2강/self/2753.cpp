#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int year;
    cin >> year;

    if(year % 4 == 0) {
        if(year % 400 == 0) { // 4의 배수이면서 400의 배수
            cout << 1;
        } else if(year % 100 == 0){ // 4의 배수이면서 100의 배수
            cout << 0;
        } else { // 4의 배수이면서 100, 400의 배수가 아닌 수
            cout << 1;
        }
    } else {   // 4의 배수가 아닌 수
        cout << 0;
    }
}