#include <iostream>

using namespace std;

int n, m;
int grid[200][200];
int bomb_cols[15];

void bomb(int c) {
    int idx2 = 0;

    for (int i = 0; i < n; i++) {
        if (grid[i][c] == 0) continue;
        else { idx2 = i; break; }
    }
    int amount = grid[idx2][c];
    if (amount == 0) return;

    for (int i = 1; i < amount; i++) {
        if (idx2 - i >= 0) grid[idx2 - i][c] = 0;
        if (c - i >= 0) grid[idx2][c - i] = 0;
        if (idx2 + i < n) grid[idx2 + i][c] = 0;
        if (c + i < n) grid[idx2][c + i] = 0;
    }
    grid[idx2][c] = 0;
    //amount대로 제거했어

    for (int j = 0; j < n; j++) {
        int idx = 0;
        int temp[200];
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 0) continue;
            temp[idx] = grid[i][j];
            idx++;
        }

        for (int i = 0; i < idx; i++) {
            grid[n - 1 - i][j] = temp[idx - 1 - i];
        }

        for (int i = idx; i < n; i++) grid[n - 1 - i][j] = 0;

    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> bomb_cols[i];
        bomb(bomb_cols[i] - 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    // Please write your code here.

    return 0;
}
