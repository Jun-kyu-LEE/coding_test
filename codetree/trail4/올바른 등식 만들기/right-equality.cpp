#include <iostream>

using namespace std;

int N, M;
int nums[100];

long long dp[100][41]; //-20~20 0 -->-20  20-->40   20-->0
bool vis[100][41];

long long go(int idx, int sum) {
    if (sum > 20 || sum < -20) return 0;
    if (idx == N) {
        if (sum == M) return 1;
        else return 0;
    }
    if (vis[idx][sum + 20]) return dp[idx][sum + 20];
    long long ways = go(idx + 1, sum - nums[idx]) + go(idx + 1, sum + nums[idx]);

    vis[idx][sum + 20] = true;
    dp[idx][sum + 20] = ways;
    return ways;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    //더하거나 빼는걸 선택하는거야
    //
    cout << go(0, 0);
    // Please write your code here.

    return 0;
}
