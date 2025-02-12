#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        // 공백있는 문자열은 getline(cin, a);
        string a;
        getline(cin, a);

        // 종료 조건
        if (a == ".")
            break;

        stack<char> s;
        bool isValid = true;

        for (auto c : a)
        {
            if (c == '(' || c == '[')
            {
                s.push(c);
            }
            else if (c == ')')
            {
                // 스택이 비어있거나 짝이 맞지 않으면 break
                if (s.empty() || s.top() != '(')
                {
                    isValid = false;
                    break;
                }
                // 맞으면 팝
                s.pop();
            }
            else if (c == ']')
            {
                // 스택이 비어있거나 짝이 맞지 않으면 break
                if (s.empty() || s.top() != '[')
                {
                    isValid = false;
                    break;
                }
                // 맞으면 팝
                s.pop();
            }
        }
        // 스택에 남아 있는 괄호 처리 : 문자열을 모두 처리한 후, 스택에 남아 있는 문자가 있으면 여는 괄호가 짝이 맞지 않다는 의미이므로 isValid를 false로 설정
        if (!s.empty())
        {
            isValid = false;
        }

        // 출력! isValid가 true 면 yes, false면 no
        if (isValid)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}