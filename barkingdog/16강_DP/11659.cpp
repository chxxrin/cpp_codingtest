#include <iostream>
#include <vector>
using namespace std;

int n, m; // 수의 개수 N과 합을 구해야 하는 횟수 M

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    vector<long> dp(n+1); // 누적 합을 저장할 배열
    dp[0] = 0;

    // 누적 합 배열 계산
    for(int i=1;i<=n;i++){
        long num;
        cin >> num; // 수열의 원소 입력
        dp[i] = dp[i-1] + num; // 누적 합 계산
    }

    // 구간 합 계산
    for(int i=0;i<m;i++) {
        int s,e;
        cin >> s >> e; // 구간의 시작 인덱스 s와 끝 인덱스 e 입력
        cout << dp[e] - dp[s-1] << '\n'; // 구간 합 계산 후 출력
    }
    return 0;

}

// #11659 : 구간합구하기4
// 1. 