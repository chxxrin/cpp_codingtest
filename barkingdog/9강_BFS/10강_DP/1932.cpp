#include <iostream>

using namespace std;

int n; // 삼각형의 높이
int arr[501][501];  // 삼각형의 각 수를 저장하는 배열
// 시작지점부터 (i, j) 위치까지 오는데 최대 합 = max(dp[i-1][j-1], dp[i-1][j]) + A[i][j] // A[i][j]는 현재 내 위치

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++) {
            cin >> arr[i][j];
        }
    }

    // DP 배열 업데이트 : 삼각형의 아래에서 위로 거꾸로 올라가면서, 각 위치에서 최대 합을 계산
    for(int i=n-1;i>=1;i--) { 
        for(int j=0;j<i;j++) {
            arr[i-1][j] += max(arr[i][j], arr[i][j+1]);
        }
    }
    cout << arr[0][0]; // 위에서 아래로 내려가는 최대 합이 저장
    return 0;


}