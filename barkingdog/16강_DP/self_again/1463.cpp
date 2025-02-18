#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[1000005]; // i를 1로 만드는 데 필요한 최소 연산 횟수, 이 배열을 채워나가면서 최종적으로 d[n]을 구하는 것이 목표

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    d[1] = 0; // 1은 이미 1이므로 연산이 필요 없음

    for(int i=2;i<=n;i++) {
        d[i] = d[i-1] + 1; // 1을 빼는 경우
        if(i % 2 == 0) { // 2로 나누는 경우
            d[i] = min(d[i], d[i/2] + 1); 
        }
        if(i % 3 == 0) { // 3로 나누는 경우
            d[i] = min(d[i], d[i/3] + 1);
        }
        // min 을 구하는 이유 : 세 가지 방법을 모두 돌면서 가장 적은 연산 횟수를 선택하기 위해서!
        // 이를 통해 d[i]는 i를 1로 만드는 최소 연산 횟수를 항상 유지
    }
    cout << d[n] << '\n'; // n을 1로 만드는 데 필요한 최소 연산 횟수 출력
}
