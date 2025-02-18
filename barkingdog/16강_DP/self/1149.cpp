#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[1005][3];
int r[1005], g[1005], b[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // 집 수 입력받기
    cin >> n;

    // r,g,b 따로따로 집마다 입력받기
    for(int i=1;i<=n;i++) { 
        cin >> r[i] >> g[i] >> b[i];
    }

    // 초기값
    d[1][0] = r[1];
    d[1][1] = g[1];
    d[1][2] = b[1];

    // dp
    for(int i=2;i<=n;i++) {
        d[i][0] = min(d[i-1][1], d[i-1][2]) + r[i];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + g[i];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + b[i];
    }
    cout << *min_element(d[n], d[n]+3); // min({d[n][0], d[n][1], d[n][2]});
}

// 1. 테이블 정의하기 
// d[i][0] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 빨강
// d[i][1] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 초록
// d[i][2] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 파랑

// 2. 점화식 찾기 
// d[k][0] = min(d[k-1][1], d[k-1][2]) + r[k]
// d[k][1] = min(d[k-1][1], d[k-1][2]) + g[k]
// d[k][2] = min(d[k-1][1], d[k-1][2]) + b[k]

// 3. 초기값 정하기
// d[1][0] = r[1]
// d[1][1] = g[1]
// d[1][2] = b[1]