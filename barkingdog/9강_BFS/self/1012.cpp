#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second
 
int board[51][51]; // 배추밭
bool vis[51][51];  // 방문여부

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n, k;

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    vis[x][y] = true;
    Q.push({x, y});

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // Corrected the condition
            if (vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> m >> n >> k;

        // Initialize the board and vis arrays for each test case
        for (int i = 0; i < n; i++) {
            fill(board[i], board[i] + m, 0);
            fill(vis[i], vis[i] + m, false);
        }

        // Read in the coordinates and mark them on the board
        int x, y;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            board[y][x] = 1;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1 && !vis[i][j]) {
                    bfs(i, j);
                    res++;
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}
