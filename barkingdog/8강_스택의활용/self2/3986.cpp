#include <iostream>
#include <stack>

using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int answer = 0;

    while (n--)
    {
        string a;
        cin >> a;

        stack<int> s;

        for (auto c : a)
        {
            if (!s.empty() && s.top() == c)
            {
                s.pop();
            }
            else
            {
                s.push(c);
            }
        }
        if (s.empty())
        {
            answer++;
        }
    }
    cout << answer << '\n';
}