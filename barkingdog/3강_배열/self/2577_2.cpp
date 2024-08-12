#include <iostream>

using namespace std;

int cnt[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int result = a*b*c;
    while(result > 0) {
        cnt[result % 10]++;
        result /= 10;
    }

    for(int i=0;i<10;i++) {
        cout << cnt[i] << '\n';
    }

}