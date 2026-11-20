#include <iostream>

using namespace std;

int n;
int grid[10][10];
bool vis[10]; //행

int result = -1;
void go(int r, int num) {
    if (r == n) {
        result = max(result, num);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i] == true) continue;
        vis[i] = true;
        int nxtNum = min(num, grid[r][i]); // 새 변수
        go(r + 1, nxtNum);
        vis[i] = false;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    go(0, 10001);
    cout << result;

    // Please write your code here.

    return 0;
}
//정확히 각 칸에 하나 각 열의 하나 선택
