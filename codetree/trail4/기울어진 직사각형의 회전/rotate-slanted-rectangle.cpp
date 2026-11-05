#include <iostream>

using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, dir;

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {1, -1, -1, 1};

int dx2[4] = {-1, -1, 1, 1};
int dy2[4] = {-1, 1, 1, -1};

void rotate(int r, int c, int m1, int m2, int m3, int m4, int d) {
    int move_num[4] = {m1, m2, m3, m4};
    int carry = grid[r][c]; // 들고 갈 값
    if (d == 0) {
        for (int dir = 0; dir < 4; dir++) {
            for (int i = 0; i < move_num[dir]; i++) {
                r += dx[dir];
                c += dy[dir];
                int t = grid[r][c]; // 원래 값 챙기기
                grid[r][c] = carry; // 들고 온 값 내려놓기
                carry = t; // 챙긴 값을 다음으로 들고 감
            }
        }
    }
    if (d == 1) {
        int move_num[4] = {m4, m3, m2, m1};
        for (int dir = 0; dir < 4; dir++) {
            for (int i = 0; i < move_num[dir]; i++) {
                r += dx2[dir];
                c += dy2[dir];
                int t = grid[r][c]; // 원래 값 챙기기
                grid[r][c] = carry; // 들고 온 값 내려놓기
                carry = t; // 챙긴 값을 다음으로 들고 감
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    // Please write your code here.
    rotate(r - 1, c - 1, m1, m2, m3, m4, dir);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
//r,c,m1,m2,m3,m4,dir
//r,c에서 시작해서 1번방향으로 m만큼 2..번 그려지는 직사각형
//4,2

//
