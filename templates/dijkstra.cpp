// 다익스트라 — 가중치 있는 최단경로 (음수 간선 없을 때)
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

// graph[u] = { {v, w}, ... }
vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // (거리, 정점)

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;          // 낡은 정보 스킵

        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// 격자에서 "이동 비용 최소" 문제도 다익스트라다.
// dy/dx 로 이웃을 만들고, 비용을 board[ny][nx] 로 두면 된다.
