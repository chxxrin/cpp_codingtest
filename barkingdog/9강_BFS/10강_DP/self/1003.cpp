#include <iostream>

using namespace std;

int t;
int n;
int fibo[42][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 초기값 설정
    fibo[0][0] = 1; // fibo(0)일 때 0이 나오는 횟수 = 1
    fibo[1][1] = 1; // fibo(1)일 때 1이 나오는 횟수 = 1
    
    for(int i=2;i<=40;i++) {
        fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
        fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
    }
    cin >> t;
    while(t--) {
        cin >> n;
        cout << fibo[n][0] << ' ' << fibo[n][1] << '\n';
    }
}

/*
1. 테이블 정하기
fibo[i][k] = 숫자 i가 k(0 or 1)를 호출한 횟수
2. 점화식 찾기
fibo[i][k] = fibo[i - 1][k] + fibo[i - 2][k]
3. 초기값 정하기
fibo[0][0] = 1, fibo[1][1] = 1
*/