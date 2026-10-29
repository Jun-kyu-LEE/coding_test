#include <iostream>

using namespace std;

int n;
int l[1001], m[1001], r[1001];

int dp[1001][3]; //i번째방 전에 l,m,r중에 하나
bool vis[1001][3];

int go(int idx,int prev){
    if(idx>n)return 0;

    if(vis[idx][prev])return dp[idx][prev];
    int best=-1e9;
    if(prev==0){
        best=max(best,go(idx+1,1)+m[idx]);
        best=max(best,go(idx+1,2)+r[idx]);
    }
    if(prev==1){
        best=max(best,go(idx+1,0)+l[idx]);
        best=max(best,go(idx+1,2)+r[idx]);
    }
    if(prev==2){
        best=max(best,go(idx+1,1)+m[idx]);
        best=max(best,go(idx+1,0)+l[idx]);
    }
    vis[idx][prev]=true;
    dp[idx][prev]=best;
    return best;

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> m[i] >> r[i];
    }

    // Please write your code here.
    int answer=-1e9;
    for(int i=0; i<3; i++){
        answer=max(answer,go(0,i));
    }
    cout<<answer;
    return 0;
}
