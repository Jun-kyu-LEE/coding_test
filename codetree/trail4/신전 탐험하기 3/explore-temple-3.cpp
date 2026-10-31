#include <iostream>

using namespace std;

int n, m;
int a[1005][105];
int dp[1005][105];
bool vis[1005][105];

 int go(int idx, int prev) {
    if (idx == n) return 0;
    if (vis[idx][prev]) return dp[idx][prev];

    int best = -1e9;
    for (int c =0; c <m; c++) {
        if (c == prev) continue;                      // 직전 층과 같은 방 X
        best = max(best, go(idx + 1, c) + a[idx][c]);
    }

    vis[idx][prev] = true;
    return dp[idx][prev] = best;
}



int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int answer=-1e9;
    for(int i=0; i<m; i++){
        answer=max(answer,a[0][i]+go(1,i));
    }
    // Please write your code here.
    cout<<answer;
    return 0;
}
//N층 Mㅂ개의 방
//바로 직전층에 들어갔던 번호의 방 들어가면 안된다

