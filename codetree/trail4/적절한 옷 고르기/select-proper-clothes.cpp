#include <iostream>

using namespace std;

int N, M;
int s[200], e[200], v[200];
//s는 옷 입기 시작 가능
//e는 옷 끝
//v는 화려함
//항상 화려함의 차이가 가장 크도록 해야해

long long dp[201][201]; //m번째일에 전에 n번옷을 입었을때 최대값
bool vis[201][201];

long long go(int day,int prev){
    if(day>M)return 0;
    if(vis[day][prev])return dp[day][prev];

    long long best=-1e9;
    for(int i=0; i<N; i++){
        //if(prev==i)continue;
        if(day>=s[i]&&day<=e[i]){
            best=max(best,go(day+1,i)+abs(v[prev]-v[i]));
        }
    }
    vis[day][prev]=true;
    dp[day][prev]=best;
    return best;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> v[i];
    }

    // Please write your code here.j
    long long answer=-1;
    for (int j = 0; j < N; j++)
        if (s[j] <= 1 && 1 <= e[j])
            answer = max(answer, go(2, j)); 
    cout<<answer;
}
//언제가 일치하는지를 보자 
//고려한 위치
//마지막에 고른 숫자의 위치
//지금까지 고른 숫자들의 합
//그러면 idx,위치만 보면 최대합은 항상 표현할수잇겠다
