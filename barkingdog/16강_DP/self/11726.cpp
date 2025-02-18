#include <iostream>

using namespace std;

int n;
int d[1002];
int mod = 10007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    d[1] = 1;
    d[2] = 2;

    for(int i=3;i<=n;i++) {
        d[i] = (d[i-1] + d[i-2]) % mod;
    }
    cout << d[n] << '\n';

}

// #11726 : 2*n 타일링
// 1. 테이블 정의하기 : d[i] = 2*i 크기의 직사각형을 채우는 방법의 수
// 2. 점화식 찾기 : d[n] = d[n-1] + d[n-2]