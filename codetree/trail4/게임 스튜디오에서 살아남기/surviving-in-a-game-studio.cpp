#include <iostream>

using namespace std;

int n;
const long long mod=1000000007;

long long dp[1001][4][4]; // [1001][3] //idx가 1000개 선택은 3개 각각 4 4하는게 더 좋으려나
bool vis[1001][4][4];

long long go(int idx,int t,int b){
    if(b==3)return 0;
    if(t==3)return 0;
    if(idx==n){
        if(t<=3&&b<=3)return 1;
        else return 0;
    }
    if(vis[idx][t][b])return dp[idx][t][b];
    
    long long ways=(go(idx+1,t,0)+go(idx+1,t+1,0)+go(idx+1,t,b+1))%mod;
    vis[idx][t][b]=true;
    dp[idx][t][b]=ways;
    return ways;

}

int main() {
    cin >> n;

    // Please write your code here.
    //n일 살아남기 위해 만들수있는 n자리의 평가 문자열의 가짓수
    //
    cout<<go(0,0,0);
    return 0;
}
