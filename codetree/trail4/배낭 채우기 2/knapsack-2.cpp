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
        for(int j=0; j<=M; j++){
            if(j<w[i])continue;
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    // Please write your code here.
    cout<<dp[M];
    return 0;
}
