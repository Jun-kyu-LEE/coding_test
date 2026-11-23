#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int n, k, m;
int grid[100][100];
int r[10000], c[10000];
bool vis[100][100];
int temp[100][100];
vector<pair<int, int>> rock;
vector<pair<int, int>> start;
int result = -1;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void go(int idx, int cnt) {
    if (cnt == m) {
        //이때 bfs계산하면 되는거지

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) vis[i][j] = false;
        }

        int count = 0;

        for (int t = 0; t < k; t++) {
            queue<pair<int, int>> q;
            int st_x = start[t].first;
            int st_y = start[t].second;
            vis[st_x][st_y] = true;
            q.push({st_x, st_y});
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                int x = cur.first;
                int y = cur.second;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] == true) continue;
                    if (temp[nx][ny] == 1) continue;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (vis[i][j] == true) count++;
        }
        result = max(result, count);
        return;
    }
    if (idx == rock.size()) return;
    int x = rock[idx].first;
    int y = rock[idx].second;

    temp[x][y] = 0;
    go(idx + 1, cnt + 1); //선택했을때

    temp[x][y] = 1;
    go(idx + 1, cnt);
}

int main() {
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) rock.push_back({i, j});
            temp[i][j] = grid[i][j];
        }

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
        start.push_back({r[i], c[i]});
    }
    go(0, 0);
    cout << result;
    // Please write your code here.

    return 0;
}
