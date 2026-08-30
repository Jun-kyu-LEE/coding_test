// 격자 탐색 (BFS / DFS) — SWEA 미로·영역 문제 단골
#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[100][100];
bool visited[100][100];

// 상, 우, 하, 좌 (시계방향)
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

inline bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

// 최단거리가 필요하면 BFS
int bfs(int sy, int sx, int ty, int tx) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    vector<vector<int>> dist(N, vector<int>(M, -1));

    q.push({sy, sx});
    visited[sy][sx] = true;
    dist[sy][sx] = 0;

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        if (y == ty && x == tx) return dist[y][x];

        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d], nx = x + dx[d];
            if (!inRange(ny, nx)) continue;
            if (visited[ny][nx]) continue;
            if (board[ny][nx] == 1) continue;   // 벽

            visited[ny][nx] = true;
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return -1;   // 도달 불가
}

// 영역 크기 / 연결요소 세기는 DFS
int dfs(int y, int x) {
    visited[y][x] = true;
    int cnt = 1;
    for (int d = 0; d < 4; ++d) {
        int ny = y + dy[d], nx = x + dx[d];
        if (!inRange(ny, nx)) continue;
        if (visited[ny][nx]) continue;
        if (board[ny][nx] == 0) continue;

        cnt += dfs(ny, nx);
    }
    return cnt;
}
