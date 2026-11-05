#include <iostream>

using namespace std;

int n;
int grid[200][200];
int r, c;

void remove(int r, int c) {
    int amount = grid[r][c];
    for (int i = 1; i < amount; i++) {
        if (r - i >= 0) grid[r - i][c] = 0;
        if (c - i >= 0) grid[r][c - i] = 0;
        if (r + i < n) grid[r + i][c] = 0;
        if (c + i < n) grid[r][c + i] = 0;
    }
    grid[r][c] = 0;

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

        for(int i=0; i<n-idx; i++)grid[i][j]=0;

        
       
    }

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    remove(r - 1, c - 1);
    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
