#include <iostream>
#include<queue>
#include<utility>
using namespace std;

int n, m, r, c;

bool vis[101][101];
int board[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    cin >> n >> m >> r >> c;

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = -1;
        }
    }

    r--; c--;
    vis[r][c] = 1;
    int amount = 1;
    board[r][c] = 0;

    for (int time = 1; time <= m; time++) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (vis[i][j]) {
                    if (board[i][j] == -1 || board[i][j] == time) continue;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = i + (amount * dx[dir]);
                        int ny = j + (amount * dy[dir]);
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] == -1) board[nx][ny] = time;
                        vis[nx][ny] = true;
                    }
                }

            }
        }
        amount *= 2;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) count++;
        }
    }
    cout << count;
    return 0;
}
//n*n 0초
//2^t-1만큼 떨어진 지점에터진다
//M초 후 격자판에 놓여있는 폭탄의 수
//1초에는 4방향
