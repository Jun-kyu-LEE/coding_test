#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
bool vis[100][100];

void dfs(int x, int y) {
    if (vis[x][y]) return;
    vis[x][y] = true;

    if (grid[x + 1][y] == 1) dfs(x + 1, y);
    if (grid[x][y + 1] == 1) dfs(x, y + 1);

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    dfs(0, 0);
    // Please write your code here.
    if (vis[n - 1][m - 1]) cout << 1;
    else cout << 0;
    return 0;
}
