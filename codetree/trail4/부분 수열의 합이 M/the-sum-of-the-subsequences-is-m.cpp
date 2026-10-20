#include <iostream>

using namespace std;

int n, m;
int A[100];
int dp[10001];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i=1; i<=m; i++)dp[i]=1001;
    // Please write your code here.
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=m; j>=1; j--){
            if(j<A[i])continue;
          

            dp[j]=min(dp[j],dp[j-A[i]]+1);
        }
    }
    if(dp[m]==1001)cout<<-1;
    else cout<<dp[m];
    return 0;
}
