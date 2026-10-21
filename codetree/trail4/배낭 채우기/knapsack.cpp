#include <iostream>

using namespace std;

int N, M;
int w[100], v[100];
int dp[10001];
int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    

    for(int i=0; i<N; i++){
        for(int j=M; j>=w[i]; j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }

    cout<<dp[M];
    // Please write your code here.

    return 0;
}
