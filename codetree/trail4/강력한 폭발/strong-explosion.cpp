#include <iostream>
#include<vector>
#include<utility>
using namespace std;

int n;
int grid[20][20];
vector<pair<int, int>> bomb;

int result = -1;

void go(int idx, bool check[20][20]) {
    if (idx == bomb.size()) { // ★ -1 제거
        int sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (check[i][j] == true) sum++;
        result = max(result, sum);
        return;
    }

    for (int i = 1; i <= 3; i++) {
        bool next[20][20]; 
        for (int a = 0; a < n; a++)
            for (int b = 0; b < n; b++)
                next[a][b] = check[a][b];

        auto cur = bomb[idx];
        int x = cur.first;
        int y = cur.second;
        if (i == 1) {
            next[x][y] = true; // ★ check → next
            if (x + 1 < n) next[x + 1][y] = true;
            if (x + 2 < n) next[x + 2][y] = true;
            if (x - 1 >= 0) next[x - 1][y] = true; // ★ > 0 → >= 0
            if (x - 2 >= 0) next[x - 2][y] = true;
        }
        if (i == 2) {
            next[x][y] = true;
            if (x + 1 < n) next[x + 1][y] = true;
            if (y + 1 < n) next[x][y + 1] = true;
            if (x - 1 >= 0) next[x - 1][y] = true;
            if (y - 1 >= 0) next[x][y - 1] = true;
        }
        if (i == 3) {
            next[x][y] = true;
            if (x + 1 < n && y + 1 < n) next[x + 1][y + 1] = true;
            if (x + 1 < n && y - 1 >= 0) next[x + 1][y - 1] = true;
            if (x - 1 >= 0 && y + 1 < n) next[x - 1][y + 1] = true;
            if (x - 1 >= 0 && y - 1 >= 0) next[x - 1][y - 1] = true;
        }
        go(idx + 1, next); // ★ 복사본을 넘김
    }
}

int main() {
    cin >> n;

    bool temp[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                bomb.push_back({i, j});
            }
            temp[i][j] = false;
        }
    }
    go(0, temp);
    cout << result;
    // Please write your code here.

    return 0;
}
//1은 해당 위치가 폭탄이 놓인 칸
//3가지중 하나의 폭탄을 선택
//1번 세로폭탄 위 아래 두칸
//2번 상하좌우
//3번 대각선 방향

//그곳에 1번 2번 3번 선택하고 체크하기
