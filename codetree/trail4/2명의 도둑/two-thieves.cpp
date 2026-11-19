#include <iostream>

using namespace std;

int n, m, c;
int weight[10][10];
int best[10][10];
int item[5];
int bestVal = -1;

void go(int k, int wSum, int vSum) {
    if (wSum > c) return;
    if (k == m) {
        bestVal = max(bestVal, vSum);
        return;
    }
    go(k + 1, wSum, vSum);
    go(k + 1, wSum + item[k], vSum + item[k] * item[k]);
}

int main() {
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j + m <= n; j++) {
            for (int k = 0; k < m; k++) item[k] = weight[i][j + k];
            bestVal = 0;
            go(0, 0, 0);
            best[i][j] = bestVal;
        }
    }
    // Please write your code here.
    int ans = 0;
    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 + m <= n; j1++) {
            for (int i2 = i1; i2 < n; i2++) {
                for (int j2 = 0; j2 + m <= n; j2++) {
                    if (i1 == i2 && j1 + m > j2) continue;
                    ans = max(ans, best[i1][j1] + best[i2][j2]);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
