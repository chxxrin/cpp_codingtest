#include <iostream>
#include <algorithm>

using namespace std;

int n; // 수열의 길이
int a[1005]; // 입력된 수열을 저장할 배열
int d[1005]; // 각 위치까지의 최대 부분 수열 합을 저장할 배열

int main() {
    ios::sync_with_stdio(0); // 입출력 속도를 빠르게 하기 위해 사용
    cin.tie(0); // cin과 cout의 묶음을 해제

    cin >> n; // 수열의 길이를 입력 받음
    for(int i=1; i<=n; i++) {
        cin >> a[i]; // 수열의 각 요소를 입력 받음
        d[i] = a[i]; // 초기화: d[i]는 최소한 a[i] 자신이 됨
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<i; j++) { // 현재 위치 i보다 앞에 있는 모든 위치 j에 대해 확인
            if(a[j] < a[i]) { // 증가하는 부분 수열의 조건
                d[i] = max(d[i], d[j] + a[i]); // 이전 위치 j까지의 최대 합에 현재 값을 더한 것과 현재 d[i]를 비교
            }
        }
    }

    cout << *max_element(d+1, d+n+1) << '\n'; // d 배열에서 가장 큰 값을 찾아 출력
    return 0;
}
