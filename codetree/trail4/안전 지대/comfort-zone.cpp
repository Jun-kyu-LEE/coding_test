#include <iostream>

using namespace std;

int N, M;
int grid[50][50];
bool vis[50][50];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int k) {
    if (vis[x][y] == true) return;
    vis[x][y] = true;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (vis[nx][ny] == true) continue;
        if (grid[nx][ny] <= k) continue;
        dfs(nx, ny, k);
    }
}

int main() {
    cin >> N >> M;

    int max_K = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (max_K < grid[i][j]) max_K = grid[i][j];
        }
    }
    int result = -1;
    int k_value = -1;
    for (int k = 1; k <= max_K; k++) {

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) vis[i][j] = false;
        }
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (vis[i][j] == false && grid[i][j] > k) {
                    count++;
                    dfs(i, j, k);
                }
            }
        }
        if (result < count) {
            result = count;
            k_value = k;
        }
    }
    // Please write your code here.
    cout << k_value << " " << result;
    return 0;
}

//K이하인 애들은 잠기게된다
//K에 따라 안전영역의 개수 확인
