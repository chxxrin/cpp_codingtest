// 응용2 : 시작점이 여러개일때 BFS

#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#define X first
#define Y second

using namespace std;

int r, c;
string board[1002];     // 미로 정보를 저장하는 문자열 배열
int dist_f[1002][1002]; // 불이 전파되는 시간
int dist_j[1002][1002]; // 지훈이가 이동하는 시간
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    // dist 거리 배열을 사용하면 fill()함수로 -1로 만들어 초기화를 해주자
    for (int i = 0; i < r; i++)
    {
        fill(dist_f[i], dist_f[i] + c, -1); // 불의 시간
        fill(dist_j[i], dist_j[i] + c, -1); // 지훈이 탈출 시간
    }

    for (int i = 0; i < r; i++)
    {
        cin >> board[i];
    }

    queue<pair<int, int>> qf;
    queue<pair<int, int>> qj;

    // 탐색
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'F') // F: 불이 난 공간
            {
                // 매 분마다 한칸씩 수평또는 수직으로 이동
                qf.push({i, j});
                dist_f[i][j] = 0;
            }
            if (board[i][j] == 'J') // J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
            {
                // 매 분마다 한칸씩 수평또는 수직으로 이동
                qj.push({i, j});
                dist_j[i][j] = 0;
            }
        }
    }

    // fire BFS
    while (!qf.empty())
    {
        auto cur_f = qf.front(); // qf에서 현재 불 위치를 가져옴
        qf.pop();

        for (int dir = 0; dir < 4; dir++) // 4방향(dx, dy)으로 불이 번질 수 있는 곳 찾기
        {
            int nx = cur_f.X + dx[dir];
            int ny = cur_f.Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) // 범위 초과 방지: nx, ny가 미로 범위를 벗어나면 continue
                continue;

            if (dist_f[nx][ny] >= 0 || board[nx][ny] == '#') // 이미 방문한 곳은 방문하지 않음, 벽('#')은 통과 불가
                continue;

            dist_f[nx][ny] = dist_f[cur_f.X][cur_f.Y] + 1; // 불이 번질 수 있는 곳이면 dist_f[nx][ny]에 시간을 저장 후 qf에 삽입
            qf.push({nx, ny});
        }
    }

    // Jihoon BFS
    while (!qj.empty())
    {
        auto cur_j = qj.front(); // qj에서 지훈이의 현재 위치를 가져옴
        qj.pop();

        for (int dir = 0; dir < 4; dir++) // 4방향(dx, dy)으로 이동할 수 있는 곳 찾기
        {
            int nx = cur_j.X + dx[dir];
            int ny = cur_j.Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) // 경계선을 벗어나면 탈출 성공 → 탈출까지 걸린 시간 출력 후 종료
            {
                cout << dist_j[cur_j.X][cur_j.Y] + 1;
                return 0;
            }

            if (dist_j[nx][ny] >= 0 || board[nx][ny] == '#') // 이미 방문한 곳은 방문하지 않음, 벽('#')은 이동 불가
                continue;

            // dist_f[nx][ny] == -1이면 불이 도달하지 않은 칸
            // dist_f[nx][ny] != -1이면 불이 이미 도달한 칸
            if (dist_f[nx][ny] != -1 && dist_f[nx][ny] <= dist_j[cur_j.X][cur_j.Y] + 1) // 불이 이미 도착했고, 불이 도착한 시간이 지훈이 도착하는 시간보다 짧거나 같으면 이동 불가
                continue;

            // dist_f[nx][ny] → 불이 (nx, ny)에 도착하는 시간
            // dist_j[cur_j.X][cur_j.Y] + 1 → 지훈이가 (nx, ny)에 도착하는 시간 (현재 위치에서 한 칸 이동)
            dist_j[nx][ny] = dist_j[cur_j.X][cur_j.Y] + 1; // 이동 가능한 곳이면 dist_j[nx][ny]에 시간을 저장 후 qj에 삽입
            qj.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}