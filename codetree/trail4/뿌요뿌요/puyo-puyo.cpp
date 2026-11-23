#include <iostream>

using namespace std;

int n;
int grid[100][100];
bool vis[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int c = 0;
void dfs(int x, int y, int value) {
    if (vis[x][y] == true) return;
    vis[x][y] = true;
    c++;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (vis[nx][ny] == true) continue;
        if (grid[nx][ny] != value) continue;
        dfs(nx, ny, value);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int count = 0;
    int max_value = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            c = 0;
            if (vis[i][j] == false) {
                dfs(i, j, grid[i][j]);
            }
            if (c >= 4) { count++; }
            max_value = max(max_value, c);

        }
    }
    cout << count << " " << max_value;
    // Please write your code here.

    return 0;
}
//같은 정수 같은 칸 4개이상 이면 블럭은 터지기
