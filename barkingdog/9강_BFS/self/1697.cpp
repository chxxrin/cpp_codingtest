#include <iostream>
#include <queue>

using namespace std;

int dist[100002]; // dist[100002] 배열은 각 위치까지의 최단 거리를 저장합니다. 초기값을 -1로 설정하여 아직 방문하지 않은 위

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    fill(dist, dist+100001, -1);

    dist[n] = 0; //  시작 위치의 거리를 0으로 설정

    queue<int> Q; // 초기화하고 시작 위치를 큐에 넣음
    Q.push(n);

    // BFS
    while(dist[k] == -1) { // 큐가 비어 있지 않고 목표 위치 k에 도달할 때까지 반복
        int cur = Q.front(); // 현재 위치 cur를 큐에서 꺼내고, 가능한 세 가지 이동을 시도
        Q.pop();

        for(int nxt : {cur-1, cur+1, 2*cur}) {
            if(nxt < 0 || nxt > 100000 ) continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1; // 이동한 위치가 범위를 벗어나지 않고, 아직 방문하지 않은 위치인 경우에만 큐에 넣고 거리를 갱신
            Q.push(nxt);
        }
    }
    cout << dist[k];


}