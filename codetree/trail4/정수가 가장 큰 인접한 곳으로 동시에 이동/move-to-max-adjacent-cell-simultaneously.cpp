#include <iostream>
using namespace std;

int n, m, t;
int grid[20][20];
int cnt[20][20]; // 칸마다 구슬 수
int next_cnt[20][20]; // 다음 초의 구슬 수

int dx[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    for (int k = 0; k < m; k++) {
        int r, c;
        cin >> r >> c;
        cnt[r - 1][c - 1] = 1; // 1번 기준 → 0번 기준
    }

    for (int sec = 0; sec < t; sec++) {
        // 1. 다음 상태 비우기
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                next_cnt[i][j] = 0;

        // 2. 구슬마다 다음 위치로 이동
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (cnt[i][j] != 1) continue;

                int best = -1, bx = i, by = j;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d], ny = j + dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (grid[nx][ny] > best) { 
                        best = grid[nx][ny];
                        bx = nx; by = ny;
                    }
                }
                next_cnt[bx][by]++;
            }

        // 3. 충돌한 칸 제거하고 반영
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cnt[i][j] = (next_cnt[i][j] == 1) ? 1 : 0;
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            answer += cnt[i][j];
    cout << answer;
    return 0;
}
