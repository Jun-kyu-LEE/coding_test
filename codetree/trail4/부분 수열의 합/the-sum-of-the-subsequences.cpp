#include <iostream>

using namespace std;

int n, m;
int A[100];



int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
  
    // Please write your code here.
    //dp[i] -->i일때의 합 
    bool dp[10001];   // m 최대값 + 1 이상

    dp[0] = true;     // 아무것도 안 고르면 합 0
    for (int i = 0; i < n; i++)
        for (int j = m; j >= A[i]; j--)   // 각 원소 한 번씩 → 거꾸로
            dp[j] = dp[j] || dp[j - A[i]];

    cout << (dp[m] ? "Yes" : "No");
    
    return 0;
}
