#include <iostream>
#include <algorithm> // max_element를 사용하기 위해 필요

using namespace std;

int n;
int a[501][501];
int d[501][501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cin >> a[i][j]; // 삼각형 배열을 입력받아 저장
        }
    }
    d[1][1] = a[1][1]; // 시작점의 초기값 설정

    for(int i=2;i<=n;i++) {
        for(int j=1;j<=i; j++) {
            // 현재 위치까지의 최대 합을 계산
            d[i][j] = max(d[i-1][j-1], d[i-1][j]) + a[i][j];
        }
    }
    // 마지막 줄에서 최대 값을 찾아 출력
    cout << *max_element(d[n] + 1, d[n] + n + 1); // d[n]의 첫 번째 요소에서 마지막 요소까지의 최대 값
}
