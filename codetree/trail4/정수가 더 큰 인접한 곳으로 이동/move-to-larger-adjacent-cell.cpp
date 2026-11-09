#include <iostream>

using namespace std;

int n;
int r, c;
int a[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    bool flag = false;
    while (1) {
        flag = false;
        cout << a[r][c] << " ";
        for (int dir = 0; dir < 4; dir++) {
            int nx = r + dx[dir];
            int ny = c + dy[dir];
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (a[nx][ny] > a[r][c]) {
                r = nx;
                c = ny;
                flag = true;
                break;

            }
        }
        if (!flag) break;

    }
    // Please write your code here.

    return 0;
}
