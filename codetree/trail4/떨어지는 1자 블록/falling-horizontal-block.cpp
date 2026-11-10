#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    //1xm의 블럭
    //k만큼의 공간을 차지 //그중에 1이있으면 떨어지는걸 멈춘다
    // Please write your code here.
    int idx = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (flag) break;
        for (int j = k - 1; j < k - 1 + m; j++) {
            if (grid[i][j] == 1) { flag = true; idx = i; }
        }
    }
    if(!flag)idx=n;

    for (int j = k - 1; j < k - 1 + m; j++) {
        grid[idx - 1][j] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

//1x M크기의 블럭이 떨어진다
//K+M-1열까지의 공간을 차지
