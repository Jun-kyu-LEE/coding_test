#include <iostream>

using namespace std;

int n, m;
int grid[20][20];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int count = 0; count < m; count++) {
        for (int num = 1; num <= n * n; num++) {
            bool flag = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (grid[i][j] == num) {
                        flag = true;
                        int max_value = -1;
                        int bx, by;
                        for (int dir = 0; dir < 8; dir++) {
                            int nx = i + dx[dir];
                            int ny = j + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                            if (max_value < grid[nx][ny]) {
                                bx = nx;
                                by = ny;
                                max_value = grid[nx][ny];
                            }
                        }
                        grid[i][j] = max_value;
                        grid[bx][by] = num;

                    }
                    if (flag) break;
                }
                if (flag) break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    // Please write your code here.

    return 0;
}
