#include <iostream>

using namespace std;

int n, m;
int r, c;
char directions[10000];

int up = 1, down = 6, front = 2, back = 5, ri = 3, le = 4;
int dice[6] = {1, 6, 2, 5, 3, 4}; // 위 아래 앞,뒤, 왼쪽,오른쪽

//
void roll(char dir) {
    if (dir == 'R') {
        int t = up;
        up = le;
        le = down;
        down = ri;
        ri = t;
    }
    if (dir == 'L') {
        int t = le;
        le = up;
        up = ri;
        ri = down;
        down = t;
    }
    if (dir == 'U') {
        int t = up;
        up = front;
        front = down;
        down = back;
        back = t;
    }
    if (dir == 'D') {
        int t = up;
        up = back;
        back = down;
        down = front;
        front = t;
    }
}

int board[105][105];

int main() {
    cin >> n >> m >> r >> c;
    int sum = 0;
    r--;
    c--;
    board[r][c] = down;

    for (int i = 0; i < m; i++) {
        cin >> directions[i];
        if (directions[i] == 'R') {
            int nc = c + 1;
            if (nc >= n) continue;
            c = nc;
            roll('R');
            board[r][c] = down;
        }
        if (directions[i] == 'L') {
            int nc = c - 1;
            if (nc < 0) continue;
            c = nc;
            roll('L');
            board[r][c] = down;
        }
        if (directions[i] == 'U') {
            int nr = r - 1;
            if (nr < 0) continue;
            r = nr;
            roll('U');
            board[r][c] = down;
        }

        if (directions[i] == 'D') {
            int nr = r + 1;
            if (nr >= n) continue;
            r = nr;
            roll('D');
            board[r][c] = down;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += board[i][j];
        }
    }
    cout << sum;
    // Please write your code here.

    return 0;
}
//1~6까지의 숫자
//NxN크기의 M번 상하좌우 한번 이동
//처음은
// u-->R
// r-->down
//donw-->left
//left-->up

//up-->left
//right-->up
//down-->right
//left-->down

//up
//up이 front
//front -->down
//down-->back
//back-->up

//down
//up=back
//back=down
//down=front
//front=back
