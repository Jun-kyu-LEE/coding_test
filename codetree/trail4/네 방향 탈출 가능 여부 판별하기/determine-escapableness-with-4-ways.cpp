#include <iostream>
#include<queue>
using namespace std;

int n, m;
int a[100][100];
bool vis[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    queue<pair<int, int>> q;
    // Please write your code here.
    q.push({0, 0});
    vis[0][0] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (a[nx][ny] == 0 || vis[nx][ny] == true) continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    if (vis[n - 1][m - 1]) cout << 1;
    else cout << 0;
    return 0;
}
