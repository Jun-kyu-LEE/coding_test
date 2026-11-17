#include <iostream>

using namespace std;

int n, m, t;
int r[2500], c[2500];
char d[2500];
int w[2500];

int board[51][51];
bool check[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void move() {
    for (int i = 0; i < m; i++) {
        if (r[i] == -1) continue;
        int dir = -1;
        if (d[i] == 'U') {
            dir = 1;
        } else if (d[i] == 'D') {
            dir = 0;
        } else if (d[i] == 'R') {
            dir = 2;
        } else if (d[i] == 'L') {
            dir = 3;
        }
        int nr = r[i] + dx[dir];
        int nc = c[i] + dy[dir];

        if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
            if (dir == 2) { dir = 3; d[i] = 'L'; }
            else if (dir == 3) { dir = 2; d[i] = 'R'; }
            else if (dir == 0) { dir = 1; d[i] = 'U'; }
            else if (dir == 1) { dir = 0; d[i] = 'D'; }
            continue;
        }
        board[nr][nc]++;
        board[r[i]][c[i]]--;
        r[i] = nr;
        c[i] = nc;
    }
}
//충돌은 구슬의 합, 방향은 가장 큰번호가 매겨져있는 구슬의 방향

void remove() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] >= 2) {
                int value = 0;
                int idx = -1;
                for (int a = 0; a < m; a++) {
                    if (i == r[a] && j == c[a]) {
                        value += w[a];
                        idx = a;
                    }
                }

                for (int a = 0; a < m; a++) {
                    if (i == r[a] && j == c[a]) {
                        if (a == idx) continue;
                        r[a] = -1;
                        c[a] = -1;
                    }
                }
                board[i][j] = 1;
                w[idx] = value;
            }
        }
    }
}

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i] >> d[i] >> w[i];
        r[i]--;
        c[i]--;
        board[r[i]][c[i]]++;
    }

    for (int time = 0; time < t; time++) {
        move();
        remove();
    }
    // Please write your code here.
    int ans = 0;
    int max_Value = -1;
    for (int i = 0; i < m; i++) {
        if (r[i] == -1) continue;
        ans++;
        max_Value = max(max_Value, w[i]);
    }
    cout << ans << " " << max_Value;
    return 0;
}
