#include <iostream>

using namespace std;

int n;
int grid[100][100];

int dx[4] = {0, -1, 0, 1}; //오 위 왼 아래
int dy[4] = {1, 0, -1, 0};

int result(int i, int j, int dir) {
    int t = 1;
    int x = i;
    int y = j;
    while (1) {
        t++;
        if (grid[x][y] == 0) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) { return t; };
            x = nx;
            y = ny;

        }
        else if (grid[x][y] == 1) {
            if (dir == 0) dir = 1;
            else if (dir == 1) dir = 0;
            else if (dir == 2) dir = 3;
            else if (dir == 3) dir = 2;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) { return t; };
            x = nx;
            y = ny;
        }
        else if (grid[x][y] == 2) {
            if (dir == 0) dir = 3;
            else if (dir == 1) dir = 2;
            else if (dir == 2) dir = 1;
            else if (dir == 3) dir = 0;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) { return t; };
            x = nx;
            y = ny;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    // Please write your code here.
    //5
    int answer = -1;
    for (int i = 0; i < n; i++) {
        answer = max(answer, result(i, 0, 0));
        answer = max(answer, result(0, i, 3));
        answer = max(answer, result(i, n - 1, 2));
        answer = max(answer, result(n - 1, i, 1));
    }
    cout << answer;
    return 0;
}
//1이면  오->위   위-->왼 왼-->아래 아래-->오
//2이면  오-->아래 위-->오 왼-->위 아래-->왼
