// "연속 부분 최대합" 문제, 카데인 알고리즘(Kadane's Algorithm)
// O(N)

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100005]; // 입력된 수열을 저장할 배열
int d[100005]; // 각 위치까지의 연속 부분 수열의 최대 합을 저장할 배열

int main() {
    ios::sync_with_stdio(0); // 입출력 속도를 빠르게 하기 위해 사용
    cin.tie(0); // cin과 cout의 묶음을 해제

    cin >> n; // 수열의 길이를 입력 받음
    for(int i=1; i<=n; i++) {
        cin >> a[i]; // 수열의 각 요소를 입력 받음
    }

    for(int i=1; i<=n; i++) {
        d[i] = max(0, d[i-1]) + a[i]; // 이전까지의 최대 합과 현재 값을 더한 것과 현재 값을 비교
    }
    cout << *max_element(d+1, d+1+n) << '\n'; // d 배열에서 가장 큰 값을 찾아 출력

    return 0;
}
