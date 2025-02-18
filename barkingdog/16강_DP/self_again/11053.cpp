// 주어진 수열에서 가장 긴 증가하는 부분 수열(LIS: Longest Increasing Subsequence)의 길이를 구하는 문제

#include <iostream>
#include <algorithm>

using namespace std;

int n; // 수열의 길이
int a[1005]; // 입력된 수열을 저장할 배열
int d[1005]; // 각 위치까지의 LIS 길이를 저장할 배열

int main() {
    ios::sync_with_stdio(0); // 입출력 속도를 빠르게 하기 위해 사용
    cin.tie(0); // cin과 cout의 묶음을 해제

    cin >> n; // 수열의 길이를 입력받음
    for(int i=1; i<=n; i++) {
        cin >> a[i]; // 수열의 각 요소를 입력받음
    }

    fill(d+1, d+1+n, 1); // LIS의 초기값을 1로 설정 (각 요소가 자기 자신만으로 LIS를 이룸)

    for(int i=1; i<=n; i++) {
        for(int j=1; j<i; j++) { // 현재 위치 i보다 앞에 있는 모든 위치 j에 대해 확인
            if(a[j] < a[i]) { // 증가하는 부분 수열의 조건
                d[i] = max(d[i], d[j] + 1); // 이전 위치 j까지의 LIS 길이에 현재 요소를 추가한 것과 현재 d[i]를 비교
            }
        }
    }

    cout << *max_element(d+1, d+1+n); // d 배열에서 가장 큰 값을 찾아 출력
    return 0;
}
