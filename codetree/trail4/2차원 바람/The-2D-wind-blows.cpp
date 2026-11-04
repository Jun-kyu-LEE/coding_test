#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];
int board[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void rotate(int r1, int c1, int r2, int c2) {
    int temp = a[r1][c1]; // ① 왼쪽 위 값을 빼둠 → 여기가 빈자리

    for (int i = r1; i < r2; i++) // ② 왼쪽 줄: 아래 값을 위로 당김
        a[i][c1] = a[i + 1][c1];

    for (int j = c1; j < c2; j++) // ③ 아랫줄: 오른쪽 값을 왼쪽으로 당김
        a[r2][j] = a[r2][j + 1];

    for (int i = r2; i > r1; i--) // ④ 오른쪽 줄: 위 값을 아래로 당김
        a[i][c2] = a[i - 1][c2];

    for (int j = c2; j > c1 + 1; j--) // ⑤ 윗줄: 왼쪽 값을 오른쪽으로 당김
        a[r1][j] = a[r1][j - 1];

    a[r1][c1 + 1] = temp; // ⑥ 빼둔 값은 한 칸 오른쪽에
}

void avg(int r1, int c1, int r2, int c2) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = a[i][j];
        }
    }

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            int count = 1;
            int sum = a[i][j];
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                count++;
                sum += a[nx][ny];
            }
            board[i][j] = sum / count;
        }
    }

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            a[i][j] = board[i][j];
        }
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        rotate(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
        avg(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    // Please write your code here.

    return 0;
}
//q번의 바람
//시계방향으로 한칸씩 shift하기
