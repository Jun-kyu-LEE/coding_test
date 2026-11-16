#include <iostream>

using namespace std;

int T;
int N, M;
int x[2500];
int y[2500];
char d[2500];
int board[51][51];

int dx[4] = {1, -1, 0, 0}; //하 상 우 좌
int dy[4] = {0, 0, 1, -1};

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = 0;
            }
        }

        for (int i = 0; i < M; i++) {
            cin >> x[i] >> y[i] >> d[i];
            x[i]--; y[i]--;
            board[x[i]][y[i]]++;
        }
        int dir;
        for (int time = 0; time < 2 * N; time++) {
            for (int i = 0; i < M; i++) {
                if (x[i] == -1) continue;
                if (d[i] == 'D') {
                    dir = 0;
                }
                else if (d[i] == 'U') {
                    dir = 1;
                }
                else if (d[i] == 'R') {
                    dir = 2;
                }
                else if (d[i] == 'L') {
                    dir = 3;
                }
                int nx = x[i] + dx[dir];
                int ny = y[i] + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                    if (dir == 0) d[i] = 'U';
                    else if (dir == 1) d[i] = 'D';
                    else if (dir == 2) d[i] = 'L';
                    else if (dir == 3) d[i] = 'R';
                    continue;
                }
                board[nx][ny]++;
                board[x[i]][y[i]]--;
                x[i] = nx; y[i] = ny;
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] >= 2) {
                        board[i][j] = -1;
                    }
                }
            }

            for (int i = 0; i < M; i++) {
                if (x[i] == -1) continue;
                if (board[x[i]][y[i]] == -1) {
                    x[i] = -1; y[i] = -1;
                }
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] == -1) board[i][j] = 0;
                }
            }
        }
        // Please write your code here.
        int ans = 0;
        for (int i = 0; i < M; i++) {
            if (x[i] != -1) ans++;
        }
        cout << ans << "\n";

    }
    return 0;
}
