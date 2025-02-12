#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;     // 숫자 개수 입력
    stack<int> S; // 스택 선언
    int cnt = 1;  // 오름차순으로 push할 숫자
    string ans;   // 결과 저장할 문자열

    while (n--)
    { // n개의 숫자 입력
        int t;
        cin >> t; // 수열의 다음 숫자 입력

        // t까지 오름차순으로 push
        while (cnt <= t)
        {
            S.push(cnt++); // cnt 증가하면서 스택에 push
            ans += "+\n";
        }

        // 스택 top이 t와 다르면 만들 수 없는 수열
        if (S.top() != t)
        {
            cout << "NO\n";
            return 0;
        }

        // 스택의 top이 t라면 pop
        S.pop();
        ans += "-\n";
    }

    cout << ans; // 정답 출력
}
