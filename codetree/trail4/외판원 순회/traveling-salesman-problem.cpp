#include <iostream>

using namespace std;

int n;
int A[11][11];

bool vis[10];

int ans = 1e9;

void go(int cur, int sum, int count) {
    if (cur == 0 && count == n) {
        ans = min(ans, sum);
        return;
    }
    for (int nxt = 0; nxt < n; nxt++) {
        if (vis[nxt] == true || nxt == cur) continue;
        if (A[cur][nxt] == 0) continue;
        vis[nxt] = true;
        go(nxt, sum + A[cur][nxt], count + 1);
        vis[nxt] = false;
    }

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    //0이 start지점

    go(0, 0, 0);
    // Please write your code here.
    cout << ans;
    return 0;
}
//1번에서 출발 -->모든 지점 한번씩 방문
//i지점에서 j지점으로 이동하는데 드는 비용 정보 Aij
//모든 정점을 겹치지않고 방문하고 되돌아오는 최소 비용의 합
//0 2 5 9
//
