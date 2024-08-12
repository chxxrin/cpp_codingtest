#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= n - i; j++) cout << ' ';
        for(int j = 1; j <= 2 * i - 1; j++) cout << '*';
        // '*'의 오른쪽 공백은 출력하지 말아야 통과합니다.
        cout << "\n";
    }
}