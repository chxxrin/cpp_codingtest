#include <iostream>

using namespace std;

int a, b, c;
int freq[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    int result = 0;
    result = a*b*c;

    while(result > 0) {
        freq[result % 10]++; // 일의자리 구하기
        result /= 10;
    }

    for(int i=0;i<10;i++) {
        cout << freq[i] << '\n';
    }

}