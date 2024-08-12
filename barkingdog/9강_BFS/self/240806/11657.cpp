#include<cstdio>
#include<queue>
#include<vector>
#include<functional>
#include<limits.h>

using namespace std;
#define MAX 20001

struct Edge {
    int v, t;
    bool operator > (const Edge& op) const {
        return t > op.t;
    }
    Edge() {}
    Edge(int _v, int _t) : v(_v), t(_t) {}
};
int T, N, M, X, C[MAX];
vector<Edge> E[MAX];

void dijkstra() {
    priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
    Edge here;
    for (int i = 1; i <= N; i++) C[i] = INT_MAX;
    C[X] = 0;
    pq.push(Edge(X, 0));
    while (!pq.empty()) {
        here = pq.top(), pq.pop();
        for (int i = 0; i < E[here.v].size(); i++) {
            Edge edge = E[here.v][i];
            if (C[edge.v] > C[here.v] + edge.t) {
                C[edge.v] = C[here.v] + edge.t;
                pq.push(Edge(edge.v, C[edge.v]));
            }
        }
    }
}

int main() {
    int s, e, t;
    scanf("%d%d%d", &N, &M, &X);
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &s, &e, &t);
        E[s].push_back(Edge(e, t));
    }

    dijkstra();
    for (int i = 1; i <= N; i++) {
        if (C[i] == INT_MAX) printf("INF\n");
        else printf("%d\n", C[i]);
    }
}