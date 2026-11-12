#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M, K;
int x[10000], y[10000];
char d[1000];
int p[1000];
bool board[101][101];

bool check(int i, int j) {
    for (int c = 0; c < M; c++) {
        if (x[c] == i && y[c] == j) {
            x[c] = 0; y[c] = 0; return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) cin >> x[i] >> y[i];

    int time = 0;
    queue<pair<int, int>> q;
    q.push({1, 1});
    board[1][1] = true;
    bool end = false;
    int head_x = 1, head_y = 1;

    for (int i = 0; i < K; i++) {
        cin >> d[i] >> p[i];
        if (end) break;

        int dx = 0, dy = 0;
        if (d[i] == 'R') dy = 1;
        if (d[i] == 'L') dy = -1;
        if (d[i] == 'D') dx = 1;
        if (d[i] == 'U') dx = -1;

        for (int s = 0; s < p[i]; s++) {
            time++;
            head_x += dx;
            head_y += dy;
            if (head_x < 1 || head_x > N || head_y < 1 || head_y > N) { // 1. 범위
                end = true;
                break;
            }

            if (!check(head_x, head_y)) { // 2. 사과 없으면 꼬리 먼저 빼기
                auto t = q.front();
                q.pop();
                board[t.first][t.second] = false;
            }

            if (board[head_x][head_y]) { // 3. 그다음 몸 충돌
                end = true;
                break;
            }

            board[head_x][head_y] = true; // 4. 머리 놓기
            q.push({head_x, head_y});
        }
    }

    cout << time;
    return 0;
}
