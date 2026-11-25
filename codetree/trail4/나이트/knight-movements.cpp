#include <iostream>
#include<queue>
using namespace std;

int n;
int r1, c1, r2, c2;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int dist[105][105];

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    queue<pair<int, int>> q;
    q.push({r1, c1});
    dist[r1][c1] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
            if (dist[nx][ny] != 0) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    // Please write your code here.
    if (dist[r2][c2] == 0) cout << -1;
    else cout << dist[r2][c2] - 1;
    return 0;
}
