#include <iostream>

using namespace std;

int N;
long long memo[51];

long long go(int n) {

    if (memo[n] != -1) return memo[n];
    memo[n] = go(n - 1) + go(n - 2);
    return memo[n];
}

int main() {
    cin >> N;
    for (int i = 0; i <= N; i++) memo[i] = -1;
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    // Please write your code here.
    go(N);
    cout << memo[N];

    return 0;
}
