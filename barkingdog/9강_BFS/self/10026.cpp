#include <iostream>
#include <queue>
#include <utility>

using namespace std;

char board[101][101];
bool vis[101][101];

int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || board[x][y] != board[nx][ny]) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int area() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                cnt++;
                bfs(i, j);
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int not_g = area();

    for (int i = 0; i < n; i++) {
        fill(vis[i], vis[i] + n, false);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'G') {
                board[i][j] = 'R';
            }
        }
    }

    int is_g = area();
    cout << not_g << " " << is_g;
    return 0;
}
