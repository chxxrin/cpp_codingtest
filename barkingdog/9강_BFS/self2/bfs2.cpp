#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502] =
    {{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 1이 파란 칸, 0이 빨간 칸에 대응

int n = 7;
int m = 10;

bool vis[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    // 큐를 pair로 선언
    queue<pair<int, int>> q;

    // 시작점은 vis와 q에 둘다 넣는다!
    vis[0][0] = 1;
    q.push({0, 0});

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        cout << '(' << cur.X << ', ' << cur.Y << ') -> ';

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }
            if (vis[nx][ny] || board[nx][ny] != 1)
            {
                continue;
            }
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}
