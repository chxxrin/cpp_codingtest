// BFS는 최단 거리 탐색에 적합하며, 동시에 여러 시작점(익은 토마토)을 처리할 수 있습니다.
// 동시에 여러 위치에서 전파되므로 한 번 방문한 칸은 최단 거리가 보장됩니다.
// 응용2 : 시작점이 여러개일때 BFS

#include <iostream>
#include <utility>
#include <queue>
#define X first
#define Y second

using namespace std;

int board[1002][1002];
int dist[1002][1002]; // 거리를 사용
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];

            // 익은 토마토는 BFS의 시작점이므로 큐에 삽입
            if (board[i][j] == 1)
            {
                q.push({i, j});
            }
            // 익지 않은 토마토는 dist[i][j]=-1로 설정해 방문 여부를 체크!
            if (board[i][j] == 0)
            {
                dist[i][j] = -1;
            }
        }
    }

    // 그래서 익은 토마토부터 BFS 실행
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] >= 0) // dist[nx][ny] >= 0이면 이미 방문했거나 익지 않아도 되는 곳이므로 건너뜁니다.
                continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // dist[nx][ny] = dist[cur.X][cur.Y] + 1로 이전 날짜 +1을 기록하며 익은 토마토를 큐에 추가합니다.
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == -1) // 모든 칸을 확인하며 익지 않은 토마토(dist[i][j] == -1)가 남아 있다면 -1을 출력하고 종료
            {
                cout << -1;
                return 0;
            }
            answer = max(answer, dist[i][j]);
        }
    }
    cout << answer;
}