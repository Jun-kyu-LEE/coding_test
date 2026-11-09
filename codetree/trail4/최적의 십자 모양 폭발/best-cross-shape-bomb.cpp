#include <iostream>

using namespace std;

int n;
int grid[50][50];
int grid2[50][50];

void bomb(int r, int c) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid2[i][j] = grid[i][j];
        }
    }

    int amount = grid2[r][c];
    for (int i = 1; i < amount; i++) {
        if (r - i >= 0) grid2[r - i][c] = 0;
        if (r + i < n) grid2[r + i][c] = 0;
        if (c - i >= 0) grid2[r][c - i] = 0;
        if (c + i < n) grid2[r][c + i] = 0;
    }
    grid2[r][c] = 0;

    for (int j = 0; j < n; j++) {
        int temp[50];
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (grid2[i][j] == 0) continue;
            temp[idx] = grid2[i][j];
            idx++;
        }

        for (int i = 0; i < idx; i++) {
            grid2[n - 1 - i][j] = temp[idx - 1 - i];
        }

        for (int i = idx; i < n; i++) grid2[n - 1 - i][j] = 0;
    }
}

int result() {
    int count_result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid2[i][j] == 0) continue;

            if (i + 1 < n) {
                if (grid2[i][j] == grid2[i + 1][j]) count_result++;
            }
            if (j + 1 < n) {
                if (grid2[i][j] == grid2[i][j + 1]) count_result++;
            }
        }
    }
    return count_result;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bomb(i, j);
            ans = max(ans, result());
        }
    }
    cout << ans;
    // Please write your code here.

    return 0;
}
