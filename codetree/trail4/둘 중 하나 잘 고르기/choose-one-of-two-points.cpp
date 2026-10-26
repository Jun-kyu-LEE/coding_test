#include <iostream>

using namespace std;

int N;
int red[201];
int blue[201];
int memo[201][201];
bool vis[201][201];


const int NEG=-1e9;

int go(int idx,int cnt){
    int b_cnt=idx-cnt;
    if(idx==2*N){
        return 0;;
    }
    if(vis[idx][cnt])return memo[idx][cnt];
    int best=NEG;

    if(cnt<N)best=max(best,go(idx+1,cnt+1)+red[idx]);
    if(b_cnt<N)best=max(best,go(idx+1,cnt)+blue[idx]);
    
    vis[idx][cnt]=true;
    memo[idx][cnt]=best;
    return best;
}

int main() {
    cin >> N;

    for (int i = 0; i < 2 * N; i++) {
        cin >> red[i] >> blue[i];
    }

    // Please write your code here.
    cout<<go(0,0);
    return 0;
}
