#include <iostream>
#include<queue>
using namespace std;

int n, h, m;
int grid[100][100];
int dist[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    cin >> n >> h >> m;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 3) { dist[i][j] = 0; q.push({i, j}); }
            else dist[i][j] = 1e9;
        }
    }
    //2-->사람 위치
    //3-->가야하는곳 위치
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        //if (grid[x][y] == 2) break;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (grid[nx][ny] == 1) continue;
            if (dist[nx][ny] != 1e9) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                if (dist[i][j] == 1e9) cout << -1 << " ";
                else cout << dist[i][j] << " ";
            }
            else cout << 0 << " ";
        }
        cout << "\n";
    }
    // Please write your code here.

    return 0;
}
