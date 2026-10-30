#include <iostream>

using namespace std;

int N, M;
int a[501];

int dp[501][101][5];
bool vis[501][101][5];

int go(int idx, int dif, int cur) {
    if (idx == N+1) return 0;
    //할수있는게 4가지가 있는거지
    if (vis[idx][dif][cur]) return dp[idx][dif][cur];

    int best = -1e9;
    if (a[idx] == cur) {
        best = max(best, go(idx + 1, dif, cur) + 1);
    } else {
        if (dif < M)
            best = max(best, go(idx + 1, dif + 1, a[idx]) + 1);
        best = max(best, go(idx + 1, dif, cur));
    }
    vis[idx][dif][cur] = true;
    dp[idx][dif][cur] = best;
    return best;
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    // Please write your code here.
    int answer=0;
    for(int i=1; i<=4; i++){
        answer=max(answer,go(1,0,i));
    }
    cout<<answer;
    return 0;
}
//인접한 두원소가 다른횟수가 M번 이하
//유사도가 가장 큰 값
//숫자는 1~4 길이 N 수열
//숫자가 바뀌는 경우가 M번 이하
//유사도가 가장 큰 수열
