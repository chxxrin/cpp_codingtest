// 미로에서 최단 거리를 찾을 때는 BFS가 가장 적절합니다.
// BFS는 같은 거리의 모든 노드를 먼저 탐색하므로, (n-1, m-1)에 처음 도달한 경우가 최단 거리입니다.
// 응용1 : 거리측정! => int dist[102][102] 배열을 사용! 이 때 fill()함수를 통해서 거리를 -1로 초기화 해줘야함
#include <iostream>
#include <utility>
#include <queue>
#define X first
#define Y second

using namespace std;

string board[102];
int dist[102][102]; // 방문표시 대신에 거리 배열을 사용!
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    // 거리 배열 초기화 : dist[i][j] == -1 → 아직 방문하지 않은 칸
    // 그러면 굳이 vis 배열을 사용하지 않아도 된다
    for (int i = 0; i < n; i++)
    {
        fill(dist[i], dist[i] + m, -1);
    }

    // BFS 시작점
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    // BFS 실행
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
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1') // 이미 방문해서 거리가 0이상이거나 이동가능한길이 아니면 패스
                continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    cout << dist[n - 1][m - 1] + 1; // dist[n-1][m-1]은 (n-1, m-1)까지 도달하는 데 걸린 이동 횟수이므로 +1을 추가하여 경로 길이를 출력
}