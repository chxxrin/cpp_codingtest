#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define X first
#define Y second
int t, h, w;
int board[1002][1002];
int visF[1002][1002];
int visS[1002][1002];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;

  for (int testNo = 0; testNo < t; testNo++) {
    bool escape = false;
    queue<pair<int, int> > Qf = {}; // 불의 큐
    queue<pair<int, int> > Qs = {}; // 상근이의 큐
    
    // 입력
    cin >> w >> h;

    // 초기화
    for (int i = 0; i < h; i++) {
      fill(visF[i], visF[i] + w, 0);
      fill(visS[i], visS[i] + w, 0);
    }

    // 입력
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        char c;
        cin >> c; // . # @ *

        if (c == '#') board[i][j] = -1; // 벽 -> -1 (통과 X)
        else {
          if (c == '@') { // 시작위치
            Qs.push({i, j}); // 상근이의 큐에 푸시
            visS[i][j] = 1; // 상근이가 방문했음 표시
          } 
          else if (c == '*') { // 불
            Qf.push({i, j}); // 불의 큐에 푸시
            visF[i][j] = 1; // 불이 방문했음 표시
          }
          board[i][j] = 0; // 나머지 칸은 0으로 표시
        }
      }

      // 불의 BFS
    while (!Qf.empty()) {
      auto cur = Qf.front();
      Qf.pop();
      for (int dir = 0; dir < 4; dir++) { // 동서남북
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        if (nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
        if (board[nx][ny] == -1) continue; // -1이면 벽통과 못하므로 패스
        if (visF[nx][ny]) continue; // 이미 불이 다녀갔으면 패스
       
        visF[nx][ny] = visF[cur.X][cur.Y] + 1; // 현재 값에 1을 더해서 다음값을 저장
        Qf.push({nx, ny}); // 그리고 그 칸을 불의 큐에 푸시
      }
    }

    // 상근이의 BFS
    while ((!Qs.empty()) && (!escape)) { // !escape == true
      auto cur = Qs.front();
      Qs.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        // 상근이가 현재 위치(cur.X, cur.Y)에서 동서남북 방향으로 한 칸 이동했을 때(nx, ny), 그 위치가 격자의 바깥인지 확인
        if (nx < 0 || h <= nx || ny < 0 || w <= ny) { // 이 조건 중 하나라도 참이면 상근이가 격자의 바깥으로 나갔다는 의미
          cout << visS[cur.X][cur.Y] << '\n'; // 상근이가 처음 위치에서 현재 위치까지 이동한 횟수(거리)
          escape = true; // 탈출 성공!
          break; 
        }
        
        if (board[nx][ny] == -1) continue;
        if (visS[nx][ny]) continue;
        if (visF[nx][ny] != 0 && visF[nx][ny] <= visS[cur.X][cur.Y] + 1) continue;
        visS[nx][ny] = visS[cur.X][cur.Y] + 1;
        Qs.push({nx, ny});
      }
    }

    if (!escape) cout << "IMPOSSIBLE" << '\n';
  }
}