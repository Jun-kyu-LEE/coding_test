#include <iostream>
#include <algorithm>
using namespace std;

int n;
int l[1001], m[1001], r[1001];

int dp[1001][3][3];    // [층][직전 선택][1층 선택]
bool vis[1001][3][3];

int val(int idx, int c) {          // c번 방의 보물 (0=L, 1=M, 2=R)
    if (c == 0) return l[idx];
    if (c == 1) return m[idx];
    return r[idx];
}

int go(int idx, int prev, int first) {
    if (idx == n) return 0;
    if (vis[idx][prev][first]) return dp[idx][prev][first];

    int best = -1e9;
    for (int c = 0; c < 3; c++) {
        if (c == prev) continue;                      // 직전 층과 같은 방 X
        if (idx == n - 1 && c == first) continue;     // 꼭대기 층은 1층과도 다르게
        best = max(best, go(idx + 1, c, first) + val(idx, c));
    }

    vis[idx][prev][first] = true;
    return dp[idx][prev][first] = best;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> l[i] >> m[i] >> r[i];

    int answer = -1e9;
    for (int f = 0; f < 3; f++)                       // 1층 방을 직접 고르고 시작
        answer = max(answer, val(0, f) + go(1, f, f));

    cout << answer;
    return 0;
}