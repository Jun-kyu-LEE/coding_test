#include <iostream>

using namespace std;

int n;

int memo[1001];

int go(int idx) {
    if (memo[idx] != -1) return memo[idx];
    memo[idx] = (go(idx - 1) + go(idx - 2)) % 10007;
    return memo[idx] % 10007;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) memo[i] = -1;
    // Please write your code here.
    memo[1] = 1;
    memo[2] = 2;
    go(n);
    cout << memo[n];
    return 0;
}
//1 -->1개
//2 -->2개

//3일때는 2+1개

//4 -->3+1 2+2
