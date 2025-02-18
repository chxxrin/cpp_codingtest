#include <iostream>

using namespace std;

int n; // 입력값 n
int d[1000005]; // 최소 연산 횟수를 저장하는 배열
int pre[1000005]; // 경로 추적을 위한 배열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; // n을 입력 받음

    d[1] = 0; // d[1]은 초기값으로 0 설정 (1을 1로 만드는 데 필요한 연산 횟수는 0)
    
    for(int i=2; i<=n; i++) {
        d[i] = d[i-1] + 1; // 기본 연산: 1을 빼는 경우
        pre[i] = i-1; // 이전 숫자는 i-1

        if(i % 2 == 0 && d[i] > d[i/2] + 1) { // 2로 나눌 수 있는 경우
            d[i] = d[i/2] + 1; // 최소 연산 횟수를 갱신
            pre[i] = i/2; // 이전 숫자를 갱신
        }
        if(i % 3 == 0 && d[i] > d[i/3] + 1) { // 3으로 나눌 수 있는 경우
            d[i] = d[i/3] + 1; // 최소 연산 횟수를 갱신
            pre[i] = i/3; // 이전 숫자를 갱신
        }
    }
    
    cout << d[n] << '\n'; // 최소 연산 횟수 출력

    int cur = n; // cur은 현재숫자
    while(true) {
        cout << cur << ' '; // 현재 숫자 출력
        if(cur == 1) break; // 현재 숫자가 1이면 종료
        cur = pre[cur]; // 이전 숫자로 이동
    }
}
