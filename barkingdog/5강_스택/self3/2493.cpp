#include <iostream>
#include <stack>

using namespace std;

int n;
stack<pair<int, int>> tower; // {탑의 높이, 탑의 인덱스} 저장

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // 비교를 위한 더미 값 : 탑보다 더 높은 가상의 값을 넣어둠
    // 왜냐하면, 탑이 비어 있는 경우 무조건 0을 출력해야 하기 때문
    // 0번 인덱스에 MAX값을 입력
    // 첫 번째 탑의 레이저는 어떤 탑에도 닿지 않을 수도 있으므로 기본적으로 "0"을 출력할 수 있도록 설정
    tower.push({100000001, 0});

    for (int i = 1; i <= n; i++)
    {
        int height;
        cin >> height;

        // 현재 탑 height보다 낮은 탑들은 스택에서 제거
        // 어차피 현재 탑보다 낮은 탑들은 레이저를 받을 수 없음
        // 더 높은 탑이 나올 때까지 제거
        while (tower.top().first < height)
        {
            tower.pop();
        }
        // 현재 남아있는 스택의 top()이 레이저를 받는 탑이 됨
        // 즉, 현재 탑의 레이저 신호를 수신하는 가장 가까운 높은 탑의 인덱스를 출력
        cout << tower.top().second << " ";

        tower.push({height, i}); // 앞으로 나올 탑들이 이 탑을 기준으로 비교하게 됨.
    }
}