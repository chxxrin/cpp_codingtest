#include <iostream>

using namespace std;


// nCr = nPr/r! = n!/r!(n-r)!
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        int ans = 1; // 조합의 결과를 저장할 변수
        int r = 1; // 분모의 초기값 (1부터 시작)

        // n < m
        for(int i=m;i>m-n;i--) { // 분자와 분모를 곱하고 나눔으로써 조합 계산
            ans *= i; // ans에 i를 곱함
            ans /= r++; // ans를 r로 나누고 r을 1 증가시킴
        }
        cout << ans << "\n";
    }
    return 0;
}