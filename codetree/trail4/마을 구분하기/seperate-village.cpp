#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int grid[25][25];
bool vis[25][25];
vector<int> result;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int c = 0;
void dfs(int x, int y) {
    if (vis[x][y] == true) return;
    vis[x][y] = true;
    c++;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (grid[nx][ny] == 0) continue;
        dfs(nx, ny);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (vis[i][j] == false && grid[i][j] == 1) {
                c = 0;
                dfs(i, j);
                result.push_back(c);
            }

        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) cout << result[i] << "\n";
    // Please write your code here.

    return 0;
}
