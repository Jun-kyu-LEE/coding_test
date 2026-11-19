#include <iostream>

using namespace std;

int n;
int num[4][4];
int move_dir[4][4];
int r, c;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int result = -1;
void go(int i, int j, int count) {
    int dir = move_dir[i][j] - 1;
    int number = num[i][j];

    for (int a = 1; a < 4; a++) {
        int nx = i + dx[dir] * a;
        int ny = j + dy[dir] * a;
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
        if (num[nx][ny] > number) go(nx, ny, count + 1);
    }
    result = max(result, count);
    return;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> move_dir[i][j];

    cin >> r >> c;
    r--;
    c--;
    // Please write your code here.
    go(r, c, 0);
    cout << result;
    return 0;
}
//시작 위치에서 방향에 있는 수들중에 더 큰수가적혀있는곳으로 최대한 많이 반복
//n by b에 각각 저장되어있어 숫자랑 move_dir이
