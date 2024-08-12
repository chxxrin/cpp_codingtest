#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int board[501][501];
	bool vis[501][501]; // 방문 여부 
	
	queue<pair<int,int> > Q;
	int n,m;

	cin >> n >> m;
	
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board[i][j];	
		}		
	}
	
    //BFS
	int area = 0; // 그림의 넓이 
	int max = 0; // 가장 큰 그림의 넓이 
	int num = 0; // 그림의 개수 
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(vis[i][j] || board[i][j]==0) // 만약 현재 셀이 이미 방문했거나 그림이 아닌 경우(0)라면 continue
				continue;
				
			vis[i][j] = 1; // 새로운 그림을 발견하면 vis[i][j]를 1로 설정
			Q.push({i,j});  // 큐에 추가
			area = 0; // area를 0으로 초기화
			num++; // num을 증가
			
			while(!Q.empty()){ // 큐가 비어있지 않으면 BFS 탐색을 계속
				pair<int,int> cur = Q.front(); // cur는 현재 탐색 중인 셀
				Q.pop(); // 큐에서 꺼낸 후 
				
				area++; // pop이 이루어질때마다 area 크기 증가
				
				for(int dir=0; dir<4; dir++){ //상하좌우 네 방향(dx와 dy)으로 이동
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					
					if(nx < 0 || nx >= n || ny < 0 || ny >=m)
						continue;
						
					if(vis[nx][ny] || board[nx][ny]==0)
						continue;
					
					vis[nx][ny]=1; // 범위를 벗어나지 않고 방문하지 않았으며 그림인 경우(1)를 큐에 추가하고 방문 처리
					Q.push({nx,ny});
				}
				
				if(max < area)
					max = area; // BFS 탐색이 끝난 후 현재 그림의 넓이를 max와 비교하여 더 큰 값을 max에 저장
				
			}
		}
	}
	
	cout << num << "\n" << max; // 그림의 개수(num)와 가장 큰 그림의 넓이(max)를 출력
	
	return 0; 

}