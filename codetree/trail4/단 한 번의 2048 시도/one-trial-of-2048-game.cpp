#include <iostream>

using namespace std;

int grid[4][4];
char dir;

int dx[4] = {1, 0, -1, 0}; //R D L U 순서
int dy[4] = {0, 1, 0, -1};

void shift(char dir) {
    if (dir == 'R') {
        for (int i = 0; i < 4; i++) {
            int idx = 0;
            int temp[4];
            for (int j = 0; j < 4; j++) {
                if (grid[i][j] == 0) continue;
                temp[idx] = grid[i][j];
                idx++;
            }
            //idx=3
            for (int j = 0; j < idx; j++) {
                grid[i][3 - j] = temp[idx - 1 - j];
            }
            for (int j = idx; j < 4; j++) {
                grid[i][3 - j] = 0;
            }
        }
    }

    if (dir == 'L') {
        for (int i = 0; i < 4; i++) {
            int idx = 0;
            int temp[4];
            for (int j = 0; j < 4; j++) {
                if (grid[i][j] == 0) continue;
                temp[idx] = grid[i][j];
                idx++;
            }

            for (int j = 0; j < idx; j++) {
                grid[i][j] = temp[j];
            }
            for (int j = idx; j < 4; j++) {
                grid[i][j] = 0;
            }
        }
    }

    if (dir == 'U') {
        for (int i = 0; i < 4; i++) {
            int idx = 0;
            int temp[4];
            for (int j = 0; j < 4; j++) {
                if (grid[j][i] == 0) continue;
                temp[idx] = grid[j][i];
                idx++;
            }

            for (int j = 0; j < idx; j++) {
                grid[j][i] = temp[j];
            }
            for (int j = idx; j < 4; j++) {
                grid[j][i] = 0;
            }
        }
    }

    if (dir == 'D') {
        for (int i = 0; i < 4; i++) {
            int idx = 0;
            int temp[4];
            for (int j = 0; j < 4; j++) {
                if (grid[j][i] == 0) continue;
                temp[idx] = grid[j][i];
                idx++;
            }

            for (int j = 0; j < idx; j++) {
                grid[3 - j][i] = temp[idx - 1 - j];
            }
            for (int j = idx; j < 4; j++) {
                grid[3 - j][i] = 0;
            }
        }
    }

}

void merge(char dir) {
    if (dir == 'R') {
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >= 1; j--) {
                if (grid[i][j] == grid[i][j - 1]) {
                    grid[i][j] += grid[i][j - 1];
                    grid[i][j - 1] = 0;
                }
            }
        }
        shift(dir);
    }

    if (dir == 'L') {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == grid[i][j + 1]) {
                    grid[i][j] += grid[i][j + 1];
                    grid[i][j + 1] = 0;
                }
            }
        }
        shift(dir);
    }

    if (dir == 'U') {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[j][i] == grid[j + 1][i]) {
                    grid[j][i] += grid[j + 1][i];
                    grid[j + 1][i] = 0;
                }
            }
        }
        shift(dir);
    }

    if (dir == 'D') {
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >= 1; j--) {
                if (grid[j][i] == grid[j - 1][i]) {
                    grid[j][i] += grid[j - 1][i];
                    grid[j - 1][i] = 0;
                }
            }
        }
        shift(dir);
    }
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> dir;
    shift(dir);
    merge(dir);
    // Please write your code here.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
//일단 해야할게 뭐가있을까
//0인부분 제거하기
//겹치는게있으면 합치기 -->이때 어떤순서로 합쳐야할지 봐야해
//R
//4 2 8이 들어오면 idx -> 뒤에서부터 4 2 8
// 0 4 2 8
// 4 2 2 4
// 0 8 8 2
// 4 2 2 2
//R이니까 뒤에서부터 확인하면서 같은게 있으면 합치기
//그리고 0지우기

//
