#include <iostream>
#include <algorithm>

using namespace std;

int n; // 퇴직 전까지 남은 일 수
int t[20]; // 각 상담을 완료하는 데 걸리는 일 수
int p[20]; // 각 상담을 완료했을 때 받을 수 있는 수익
int d[20]; // i번째 날부터 퇴직 전까지 얻을 수 있는 최대 수익을 저장하는 배열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> t[i] >> p[i]; // 각 상담의 기간과 수익을 입력받음
    }

    for(int i=n; i>=1; i--) { // n번째 날부터 역순으로 탐색
        if(i + t[i] <= n + 1) { // 현재 상담을 수행할 수 있는 경우
            d[i] = max(d[i + t[i]] + p[i], d[i + 1]);
            // 상담을 수행한 경우와 수행하지 않은 경우 중 최대값을 선택
        } else {
            d[i] = d[i + 1]; // 현재 상담을 수행할 수 없는 경우 다음 날로 넘어감
        }
    }
    cout << *max_element(d + 1, d + 1 + n); // 최대 수익을 출력
}
