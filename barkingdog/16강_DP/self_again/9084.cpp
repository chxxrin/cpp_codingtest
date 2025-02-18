#include <iostream>
using namespace std;

int t, n, m;
int a[10005];
int d[10005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        fill(d, d + 10005, 0);  // 매 테스트 케이스마다 DP 테이블 초기화

        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];  // 각 동전의 가치 입력
        }

        cin >> m;
        d[0] = 1;  // 기본 값 설정: 금액 0을 만드는 방법은 아무 동전도 사용하지 않는 1가지 방법뿐
        for(int i = 1; i <= n; i++) {
            for(int j = a[i]; j <= m; j++) {
                d[j] += d[j - a[i]];  // 현재 금액을 만들 수 있는 방법에 이전 금액에서 동전 a[i]를 추가하는 방법을 더함
            }
        }

        cout << d[m] << '\n';  // 목표 금액 m을 만들 수 있는 방법의 수 출력
    }
}
