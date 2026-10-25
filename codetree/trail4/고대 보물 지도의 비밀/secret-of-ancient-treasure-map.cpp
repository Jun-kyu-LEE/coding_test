#include <iostream>

using namespace std;

int n, k;
int numbers[100000];
long long dp[100000][11]; //i까지 왔을때 최대합
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    long long answer = -1e18;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = -1e18;
        }

        if (numbers[i] >= 0) {
            for (int j = 0; j <= k; j++) {
                if (i > 0 && dp[i - 1][j] != -1e18) dp[i][j] = dp[i - 1][j] + numbers[i];
            }

            dp[i][0] = max(dp[i][0], (long long)numbers[i]);
        }
        else {
            for (int j = 1; j <= k; j++)
                if (i > 0 && dp[i - 1][j - 1] != -1e18) dp[i][j] = dp[i - 1][j - 1] + numbers[i];

            if (k >= 1) dp[i][1] = max(dp[i][1], (long long)numbers[i]);
        }

        for (int j = 0; j <= k; j++)
            answer = max(answer, dp[i][j]);
    }
    cout << answer;
    return 0;
}
//N개의 정수가 연속되게 선택
//연속된 정수를 선택할때 음수는 최대 K개
