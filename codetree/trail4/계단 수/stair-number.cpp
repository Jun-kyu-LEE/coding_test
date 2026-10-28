#include <iostream>
#include<string>
using namespace std;

int n;

const long long mod = 1000000007;

long long dp[1001][10];
bool vis[1001][10];

long long go(int length, int num) {
    if (num > 9) return 0;
    if (num < 0) return 0;
    if (length == n) return 1;
    if (vis[length][num]) return dp[length][num];

    long long ways = (go(length + 1, num + 1) + go(length + 1, num - 1)) % mod;
    vis[length][num] = true;
    dp[length][num] = ways;

    return ways;

}

int main() {
    cin >> n;

    // Please write your code here.
    long long answer = 0;
    for (int i = 1; i <= 9; i++) {
        answer += go(1, i);
        answer %= mod;
    }
    cout << answer;
    return 0;
}
