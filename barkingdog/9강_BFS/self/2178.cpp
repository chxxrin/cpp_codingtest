#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

#define X first
#define Y second
string board[102]; //  미로의 상태를 저장하는 문자열 배열.
int dist[102][102]; // 각 위치까지의 최단 거리를 저장하는 배열. 초기에는 모두 -1로 설정하여 방문하지 않았음을 표시
int n,m; // 미로의 크기.
int dx[4] = {1,0,-1,0}; // 상하좌우 네 방향을 나타내는 배열.
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 나타내는 배열.

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) // board 배열에 미로의 상태를 입력받음
    cin >> board[i];

  for(int i = 0; i < n; i++) fill(dist[i],dist[i]+m,-1); // dist 배열을 -1로 초기화하여 방문하지 않은 위치를 표시

  queue<pair<int,int> > Q;
  Q.push({0,0}); // 시작점 (0, 0)을 큐에 삽입
  dist[0][0] = 0; // 시작점의 거리를 0으로 초기화

  // BFS
  while(!Q.empty()){
    auto cur = Q.front(); // 1. 현재 위치를 cur에 저장
    Q.pop(); // 2. 현재 위치 cur를 큐에서 꺼냄

    for(int dir = 0; dir < 4; dir++){ // 상하좌우 네 방향으로 이동 가능한지 확인
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 이동하려는 위치 nx, ny가 미로 범위를 벗어나면 continue.
      if(dist[nx][ny] >= 0 || board[nx][ny] != '1') continue; // 이미 방문했거나 이동할 수 없는 칸이면 continue.
      dist[nx][ny] = dist[cur.X][cur.Y]+1; // 이동 가능한 칸이면 현재 위치의 거리에서 1을 더하여 dist[nx][ny]에 저장
      Q.push({nx,ny}); // 큐에 nx, ny를 삽입하여 다음 탐색을 준
    }
  }
  cout << dist[n-1][m-1]+1; // 문제의 특성상 거리+1이 정답, 탐색이 완료되면 도착지(n-1,m-1)의 거리에 1을 더하여 출력
}