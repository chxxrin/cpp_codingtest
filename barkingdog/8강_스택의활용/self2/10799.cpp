#include <iostream>
#include <stack>
typedef long long ll;

using namespace std;

string str;
ll ans = 0; // 최종적으로 계산된 쇠막대기 조각의 개수를 저장
stack<char> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    // 문자열 순회
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(') // 여는 괄호가 나오면 스택에 푸시
        {
            s.push(str[i]);
        }
        else // 닫는 괄호가 나오면
        {
            // 직전이 여는 괄호 (라면, 이는 "쇠막대기"가 시작될 때를 의미
            if (str[i - 1] == '(')
            {
                s.pop(); // s.pop()하여 여는 괄호를 제거
                // ans += s.size()는 여는 괄호들이 많이 쌓여 있을 때, 닫는 괄호가 나오면 그만큼의 쇠막대기 조각이 추가된다는 의미
                ans += s.size(); // 현재 스택에 있는 괄호들의 개수만큼 조각이 추가
            }
            else // 직전이 여는 괄호가 아니면, 이는 닫는 괄호가 하나의 막대를 끝내는 경우
            {
                s.pop(); // 핍하고
                ans++;   // 조각 하나가 추가되므로 ans++
            }
        }
    }
    cout << ans << '\n';
    return 0;
}