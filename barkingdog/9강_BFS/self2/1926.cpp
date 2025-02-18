#include <iostream>
#include <utility>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[501][501];       // 2D 격자 (0: 빈칸, 1: 그림)
bool vis[501][501];        // 방문 여부 저장 (true: 방문함, false: 방문 안 함)
int n, m;                  // 격자의 크기 (행: n, 열: m)
int dx[4] = {1, 0, -1, 0}; // x 방향 이동 (오른쪽, 위, 왼쪽, 아래)
int dy[4] = {0, 1, 0, -1}; // y 방향 이동

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int mx = 0;  // 최대 그림 크기
    int num = 0; // 그림 개수

    // 이중 for문을 사용해 전체 board를 탐색
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // board[i][j] == 0 → 빈칸이면 무시
            // vis[i][j] == true → 이미 방문한 곳이면 무시
            if (board[i][j] == 0 || vis[i][j])
                continue;

            // 새로운 그림 발견 (board[i][j] == 1 이고, 방문한 적 없을 때)
            num++; // 새로운 그림 개수 증가
            queue<pair<int, int>> q;
            q.push({i, j}); // BFS 시작점 추가
            vis[i][j] = 1;  // 방문 표시

            // BFS 실행
            int area = 0; // 현재 그림의 넓이 저장

            while (!q.empty())
            {
                area++; // 현재 위치 포함하여 영역 크기 증가

                pair<int, int> cur = q.front();
                q.pop();

                // 네 방향 탐색
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) // 범위 초과하면(nx < 0 또는 nx >= n) 무시
                        continue;
                    if (vis[nx][ny] || board[nx][ny] != 1) // 이미 방문했거나(vis[nx][ny] == true), 1이 아니면 무시
                        continue;

                    // 새로운 (nx, ny)를 queue에 넣고 방문 표시
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            mx = max(mx, area); // 현재 그림의 넓이와 기존 최대값 비교 후 갱신
        }
    }
    cout << num << '\n'
         << mx << '\n';
}