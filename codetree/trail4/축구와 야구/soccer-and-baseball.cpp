#include <iostream>

using namespace std;

int n;
int s[1000];
int b[1000];

//
long long dp[1001][12][10]; //idx이고 s랑 b일때 최대값
bool vis[1001][12][10];
//축구 11명 야구 9명
//능력의 합이 최대 -->N명의 학생들  축구팀,야구팀
//아아 N명의 학생들중 합이 최대가 되도록 선택
//sum을 idx s,b로 표현 가능하지

long long go(int idx,int soccer,int baseball){
    if(idx>n)return 0;
    if(soccer==11&&baseball==9)return 0;
   
    if(vis[idx][soccer][baseball])return dp[idx][soccer][baseball];

    long long neg=-1;
    if(soccer<11){
        neg=max(neg,go(idx+1,soccer+1,baseball)+s[idx]);
    }
    if(baseball<9){
        neg=max(neg,go(idx+1,soccer,baseball+1)+b[idx]);
    }
    neg=max(neg,go(idx+1,soccer,baseball));

    vis[idx][soccer][baseball]=true;
    dp[idx][soccer][baseball]=neg;
    return neg;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> b[i];
    }

    // Please write your code here. 
    cout<<go(0,0,0);

    return 0;
}
