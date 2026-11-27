#include <iostream>

using namespace std;

int n;

long long memo[1001];
long long const mod = 10007;

int go(int idx) {
    if (memo[idx] != -1) return memo[idx];
    memo[idx] = (go(idx - 2) % mod + go(idx - 3) % mod) % mod;
    return memo[idx];
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) memo[i] = -1;
    // Please write your code here.
    memo[1] = 0;
    memo[2] = 1;
    memo[3] = 1;
    cout << go(n);
    return 0;
}
