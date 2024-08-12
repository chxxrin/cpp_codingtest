#include <iostream>
#include <algorithm>

using namespace std;

int n; // 정수의 개수
int m; // 두 수의 차이
int a[100005]; // 수열
int minvalue = 0x7fffffff; // 두 수의 차이 중 최소값을 저장하기 위한 변수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 두 수 입력
    cin >> n >> m;
    // 수열의 요소들을 배열에 저장
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
 
    // binary_search 할거니까 먼저 배열을 정렬
    sort(a, a+n);

    // 슬라이딩 윈도우, 투포인터
    int end = 0;
    for(int start = 0; start < n; start++) {
        while (end < n && a[end] - a[start] < m) { 
            end++;
        }
        // end가 범위를 벗어나면 종료
        if(end == n) {
            break;
        }
        minvalue = min(minvalue, a[end] - a[start]); // 현재까지 발견한 최소 차이를 갱신
    }
    cout << minvalue;
}