#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[100005]; // 제곱수 항의 최소 개수를 저장하는 DP 테이블

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        d[i] = i; // 초기값으로 d[i]를 최대값 i로 설정 (모든 항이 1^2인 경우)
        for(int j = 1; j * j <= i; j++) { // j는 제곱수
            d[i] = min(d[i], d[i - j * j] + 1); // i에서 j^2를 뺀 값의 최소항 + 1
        }
    }
    cout << d[n] << '\n';
}
