#include <iostream>

using namespace std;

int n;
long long mod = 1000000000;
long long d[101][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // 초기화 
    // 길이가 1인 계단 수는 각 숫자 1부터 9까지 각각 하나씩 존재
    // 따라서 d[1][i]를 1로 초기화
    // 숫자 0은 계단 수의 첫 자리에 올 수 없으므로 제외
    for(int i=1;i<=9;i++) {
        d[1][i] = 1;
    }

    for(int i=2;i<=n;i++) {
        for(int j=0;j<=9;j++) { 
            if(j != 0) { // 인접한 자리의 숫자 차이가 1이므로, j가 0이 아닌 경우와 9가 아닌 경우를 조건문으로 확인
                d[i][j] += d[i-1][j-1]; // 마지막 숫자가 j일 때, 이전 자리의 숫자가 j-1인 경우
            }
            if(j != 9) {
                d[i][j] += d[i-1][j+1]; // 마지막 숫자가 j일 때, 이전 자리의 숫자가 j+1인 경우
            }
            d[i][j] %= mod;
        }
    }
    long long ans = 0;
    for(int i=0;i<=9;i++) {
        ans += d[n][i];
    }
    ans %= mod;
    cout << ans << '\n';
}