// 수빈이가 n에서 출발해 k까지 가장 빠르게 도달하는 최소 이동 횟수 => BFS

#include <iostream>
#include <utility>
#include <queue>
#define X first
#define Y second

using namespace std;

int n, k;
int dist[100002]; // 위치 i까지 가는 최소 이동 횟수를 저장하는 배열

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    // 거리를 활용할것이므로 fill()함수로 초기화 : 모든 위치를 미방문(-1) 상태로 초기화
    fill(dist, dist + 100001, -1);

    // BFS를 위한 큐 선언
    queue<int> q;

    // 초기값 설정
    q.push(n);   // 시작 위치 n을 큐에 넣음
    dist[n] = 0; // 시작점이므로 이동 횟수는 0

    while (dist[k] == -1) // 동생의 위치 k에 도달할 때까지 반복
    {
        int cur = q.front();
        q.pop();

        // 현재 위치에서 이동할 수 있는 곳 탐색
        for (int nxt : {cur - 1, cur + 1, 2 * cur}) // 이동 가능한 세 가지 경우를 탐색
        {
            // 범위 체크
            if (nxt < 0 || nxt > 100000) // 범위를 벗어나면 continue → nxt가 0보다 작거나 100000보다 크면 이동 불가
                continue;

            // 방문 체크
            if (dist[nxt] != -1) // 이미 방문한 곳이면 continue → 이미 방문한 곳이면 다시 방문할 필요 없음 (최단 거리 보장)
                continue;

            // 거리 갱신 & 큐에 추가
            dist[nxt] = dist[cur] + 1; // 방문하지 않은 곳이면 최단 거리 갱신 현재 위치 cur에서 한 번 이동했으므로 dist[nxt] = dist[cur] + 1
            q.push(nxt);
        }
    }
    cout << dist[k]; // dist[k]: k까지 도달하는 최소 이동 횟수를 출력
}