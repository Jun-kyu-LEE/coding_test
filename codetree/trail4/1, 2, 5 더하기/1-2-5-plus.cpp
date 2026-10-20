#include <iostream>

using namespace std;

int n;
int dp[1001];
int main() {
    cin >> n;
    //1,2,5로 하는거잖아
    int num[3]={1,2,5};
    dp[0]=1;
    dp[1]=1;
    //2 1+1 2 
   
    for(int i=2; i<=n; i++){
        for(int j=0; j<3; j++){
            if(i<num[j])continue;
            dp[i]+=dp[i-num[j]]; //전에 값에서 어케 오는지를 정하기
            dp[i]%=10007;
        }
    }
    // Please write your code here.
    cout<<dp[n];
    return 0;
}
