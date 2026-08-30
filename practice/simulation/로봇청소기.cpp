#include <iostream>
#include <cstring>
using namespace std;

// 0=북, 1=동, 2=남, 3=서
int dx[4] = { -1, 0, 1, 0 };  // 행 이동
int dy[4] = { 0, 1, 0, -1 };  // 열 이동

bool vis[51][51];
int board[51][51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, M;
        cin >> N >> M;

        int x, y, d;
        cin >> x >> y >> d;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> board[i][j];

        memset(vis, 0, sizeof(vis));   // 테스트케이스마다 초기화 필수

        int count = 0;

        while (1) {
            // 1. 현재 칸 청소
            if (!vis[x][y]) {
                vis[x][y] = true;
                count++;
            }

            // 2~4. 반시계로 돌면서 갈 곳 찾기
            bool moved = false;
            for (int i = 0; i < 4; i++) {
                d = (d + 3) % 4;              // 반시계 90도
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (board[nx][ny] == 0 && !vis[nx][ny]) {
                    x = nx;
                    y = ny;
                    moved = true;
                    break;
                }
            }
            if (moved) continue;

            // 5. 네 방향 다 막힘 -> 후진 (방향 유지)
            int bx = x - dx[d];
            int by = y - dy[d];

            if (board[bx][by] == 1) break;    // 뒤가 벽이면 종료

            x = bx;
            y = by;
        }

        cout << "#" << tc << " " << count << "\n";
    }
}