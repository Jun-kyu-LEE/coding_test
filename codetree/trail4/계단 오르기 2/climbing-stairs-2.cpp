#include <iostream>

using namespace std;

int n;
int coin[1001];

int dp[1001][4];
bool visited[1001][4];
const int NEG=-1e9;


int go(int idx,int cnt){
    if(idx==n){
        return 0;
    }
    if(idx>n)return NEG;
    if(visited[idx][cnt])return dp[idx][cnt];

    int best=NEG;

    if(cnt<3){
        best=max(best,go(idx+1,cnt+1)+coin[idx+1]);
    }
    best=max(best,go(idx+2,cnt)+coin[idx+2]);

    visited[idx][cnt]=true;
    return dp[idx][cnt]=best;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }
   
   cout<<go(0,0);

   
}
