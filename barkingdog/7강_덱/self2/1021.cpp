#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    deque<int> dq;

    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }

    int answer = 0;

    while (m--)
    {
        // 특정 숫자 위치 찾기
        int t;
        cin >> t;

        // 숫자 t의 위치를 찾는다.
        int idx = find(dq.begin(), dq.end(), t) - dq.begin();

        // 최소 이동 연산 수행
        while (dq.front() != t)
        {
            if (idx < dq.size() - idx) // idx < dq.size() - idx 조건을 통해 왼쪽으로 이동할지 오른쪽으로 이동할지 결정
            {
                // 왼쪽 회전이 더 빠르면 → push_back(dq.front()) & pop_front()
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else
            {
                // 오른쪽 회전이 더 빠르면 → push_front(dq.back()) & pop_back()
                dq.push_front(dq.back());
                dq.pop_back();
            }
            answer++;
        }
        dq.pop_front(); // 그 수를 제거하기!
    }
    cout << answer;
}