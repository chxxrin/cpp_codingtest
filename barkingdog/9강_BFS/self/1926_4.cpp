#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int board[505][505];
bool vis[505][505];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int> > Q;
    int num = 0;
    int max_area = 0;
    int area = 0;

    for(int i=0; i<n;i++) {
        for(int j=0;j<m;j++) {
            if(vis[i][j] || board[i][j] != 1) continue;
            vis[i][j] = 1;
            Q.push({i, j});
            area = 0;
            num++;

            while(!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                area++;
                for(int dir=0;dir<4;dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny]!=0) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});

                }
                if(max_area < area) {
                    max_area = area;
                }

            }
        }
    }
    cout << num << '\n' << max_area;
}
