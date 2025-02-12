#include <iostream>
#include <stack>

using namespace std;

int k;
int answer = 0;
stack<int> S;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;

    // 입력할때마다 스택을 관리해야하므로 입력과 동시에 push pop을 진행
    while (k--)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            S.pop();
        }
        else
        {
            S.push(n);
        }
    }

    // 스택에 쌓여 있는 모든 값을 더해줌
    while (!S.empty())
    {
        answer += S.top();
        S.pop();
    }
    cout << answer;
}