#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[503][503]; // 삼각형의 각 숫자를 저장하는 배열
int d[503][503]; // 각 위치까지의 최대 합을 저장하는 DP 배열

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; // 삼각형의 높이를 입력 받음
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cin >> a[i][j]; // 삼각형의 각 숫자를 입력 받음
        }
    }

    d[1][1] = a[1][1]; // 꼭대기의 값을 초기화

    // DP를 이용하여 최대 합을 계산
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            // 현재 위치 d[i][j]의 최대 합은 이전 단계의 두 가지 가능한 경로 중 큰 값과 현재 값을 더한 것
            d[i][j] = max(d[i-1][j-1], d[i-1][j]) + a[i][j];
        }
    }

    // 마지막 행의 최대값을 구하여 출력
    cout << *max_element(d[n] + 1, d[n] + 1 + n);
}
