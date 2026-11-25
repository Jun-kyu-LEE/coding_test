#include <iostream>
#include<queue>
using namespace std;

int n, m;
int a[100][100];
int dist[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int INF = 1e9;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            dist[i][j] = INF;
        }
    }
    queue<pair<int, int>> q;

    q.push({0, 0});
    dist[0][0] = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (a[nx][ny] == 0) continue;
            if (dist[nx][ny] != INF) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    if (dist[n - 1][m - 1] == INF) cout << -1;
    else cout << dist[n - 1][m - 1];
    // Please write your code here.

    return 0;
}
