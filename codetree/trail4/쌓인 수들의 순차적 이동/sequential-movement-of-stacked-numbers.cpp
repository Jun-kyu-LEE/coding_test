#include <iostream>
#include<vector>

using namespace std;

int n, m;
//int grid[20][20];
int move_nums[100];
vector<int> grid[21][21];

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            grid[i][j].push_back(num);
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> move_nums[i];
        bool done = false;
        for (int x = 0; x < n; x++) {
            if (done) break;
            for (int y = 0; y < n; y++) {
                if (done) break;
                for (int s = 0; s < grid[x][y].size(); s++) {
                    if (grid[x][y][s] == move_nums[i]) {
                        done = true;
                        int max_val = -1;
                        int bx = -1, by = -1;
                        for (int dir = 0; dir < 8; dir++) {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                            for (int t = 0; t < grid[nx][ny].size(); t++) {
                                if (max_val < grid[nx][ny][t]) {
                                    max_val = grid[nx][ny][t];
                                    bx = nx;
                                    by = ny;
                                }
                            }

                        }
                        if (max_val == -1) break;

                        for (int a = s; a < grid[x][y].size(); a++) {
                            //if (grid[x][y][a] == -1) continue;
                            grid[bx][by].push_back(grid[x][y][a]);
                            //grid[x][y][a] = -1;
                        }
                        grid[x][y].resize(s);
                        break;
                        //bx,by자리에 어디까지할지 찾아야해
                        //7 1

                    }
                }
            }
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j].size() == 0) cout << "None";
            else {
                for (int s = grid[i][j].size() - 1; s >= 0; s--) {
                    cout << grid[i][j][s] << " ";
                }
            }
            cout << "\n";
        }
    }
    // Please write your code here.

    return 0;
}
