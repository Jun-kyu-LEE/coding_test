#include <iostream>

using namespace std;

int n;
int profit[101];
 int dp[101];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> profit[i];
    }
    //i+1일때의 길이야 
    // Please write your code here.
    dp[0]=0;
   dp[1]=profit[1];

    for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
        if(j<i)continue;
        dp[j]=max(dp[j],dp[j-i]+profit[i]);
       }
    }
    
    cout<<dp[n];
}
// 1   1 2 3 4 5 까지 모두 업데이트
// 2   dp[i+j] 2,4,...,n 
// 3  dp[1]+dp[2] profit[3]
//4 dp[3]+dp[1],dp[2]+dp[2],dp[4]   