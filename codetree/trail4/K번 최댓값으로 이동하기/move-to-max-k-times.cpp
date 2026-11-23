#include <iostream>
#include<queue>
using namespace std;

int n, k;
int grid[100][100];
int r, c;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool vis[100][100];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;
    r--;
    c--;
    for (int count = 0; count < k; count++) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = false;
            }
        }

        int val = grid[r][c];
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = true;
        int nxt_r = -1; int nxt_c = -1;
        int max_val = -1;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (grid[nx][ny] >= val) continue;
                if (vis[nx][ny] == true) continue;
                if (grid[nx][ny] > max_val ||
                    (grid[nx][ny] == max_val && (nx < nxt_r || (nx == nxt_r && ny < nxt_c)))) {
                        max_val = grid[nx][ny];
                        nxt_r = nx; nxt_c = ny;
                    }
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
        if (nxt_r == -1) break;
        r = nxt_r;
        c = nxt_c;
    }
    // Please write your code here.
    cout << r + 1 << " " << c + 1;
    return 0;
}
//상하좌우 이동경로사의 모든 숫자가 x보다 작아야한다
//만약에 2개이상이면 행번호가 작은거부터 열번호가 작은거부터
//왼쪽 위쪽부터
//이동가능한 칸들중 최대값으로 이동한다
//max값들 찾고 왼쪽방향부터 찾자. 그리고 업데이트 안하기
//위,왼,오,아래
