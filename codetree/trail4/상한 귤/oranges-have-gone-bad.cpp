#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int n, k;
int grid[100][100];
int temp[100][100];
int dist[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> st;

int main() {
    cin >> n >> k;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            dist[i][j] = 1e9;
            if (grid[i][j] == 2) { dist[i][j] = 0; q.push({i, j}); }
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (grid[nx][ny] == 0) continue;
            if (dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) cout << -1 << " ";
            else if (dist[i][j] == 1e9) cout << -2 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
//최초로 상하게 되는 시간을 구하는거야
//0이면 continue
//K개의 2상한귤
//상한귤로부터 1초에 다 그거된다
