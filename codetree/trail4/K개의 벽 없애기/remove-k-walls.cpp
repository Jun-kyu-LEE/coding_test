#include <iostream>
#include<queue>
using namespace std;

int n, k;
int grid[100][100];
int dist[100][100];
int r1, c1, r2, c2;
vector<pair<int, int>> wall;
int temp[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int result = 1e9;
void go(int idx, int count) {
    if (count == k) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = 1e9;
            }
        }

        queue<pair<int, int>> q;
        q.push({r1, c1});
        dist[r1][c1] = 0;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (temp[nx][ny] == 1) continue;
                if (dist[nx][ny] != 1e9) continue;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
        if (dist[r2][c2] != 1e9) result = min(result, dist[r2][c2]);
        return;
    }
    if (idx >= wall.size()) return;
    int x = wall[idx].first;
    int y = wall[idx].second;
    go(idx + 1, count);
    temp[x][y] = 0;
    go(idx + 1, count + 1);
    temp[x][y] = 1;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) wall.push_back({i, j});
            temp[i][j] = grid[i][j];
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;
    go(0, 0);
    if (result == 1e9) result = -1;
    cout << result;
    // Please write your code here.

    return 0;
}
