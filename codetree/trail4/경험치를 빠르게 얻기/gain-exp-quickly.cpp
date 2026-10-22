#include <iostream>

using namespace std;

int n, m;
int e[100], t[100];

int dp[10001]; //i시간일때 얻을수있는 최대 경험치

int main() {
    cin >> n >> m;
    int time_sum = 0;
    int ex_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> e[i] >> t[i];
        time_sum += t[i];
    }

    //일단 time_sum일때 경험치 합도 동일할꺼 아니야
    for (int i = 0; i <= time_sum; i++) dp[i] = -1;
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = time_sum; j >= 0; j--) {
            if (dp[j] == -1) continue;
            dp[j+t[i]]=max(dp[j+t[i]],dp[j]+e[i]);
        }
    }
    int answer = -1;
    for (int i = 0; i <= time_sum; i++) {
        if (dp[i] >= m && dp[i] != -1) { answer = i; break; }
    }
    cout << answer;

    // Please write your code here.

    return 0;
}
