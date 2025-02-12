#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> S;

    while (n--)
    {
        string c;
        cin >> c;

        if (c == "push")
        {
            int t;
            cin >> t;
            S.push(t);
        }
        // empty() 먼저 확인!
        else if (c == "pop")
        {
            if (S.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << S.top() << '\n';
                S.pop();
            }
        }
        else if (c == "size")
        {
            cout << S.size() << '\n';
        }
        else if (c == "empty")
        {
            cout << (int)S.empty() << '\n';
        }
        // empty() 먼저 확인!
        else if (c == "top")
        {
            if (S.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << S.top() << '\n';
            }
        }
    }
}