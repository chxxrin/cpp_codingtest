#include <iostream>
#include <queue>

using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;

    int n;
    cin >> n;

    // queue 만들기
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() != 1)
    {
        q.pop();           // 첫 번째 카드 버리기
        q.push(q.front()); // 다음 카드를 뒤로 보내기
        q.pop();           // 뒤로 보낸 카드 제거!!
    }

    cout << q.front();
}