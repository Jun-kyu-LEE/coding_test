#include <iostream>
#include<string>
using namespace std;

int n, k;
string str;

int dp[1001][21][2]; //i번째 수정 k번 이동 오른쪽 또는 왼쪽의 위치일때 최대 수정의 개수
bool vis[1001][21][2];

int go(int idx, int mov, int cur) {
    if (idx == n) return 0;


    if (vis[idx][mov][cur]) return dp[idx][mov][cur];

    int best = -1e9;
    char c;
    if (cur == 0) c = 'L';
    else c = 'R';
    if (str[idx] == c) {
        best = max(best, go(idx + 1, mov, cur) + 1);
    } else {
        int t;
        if (c == 'L') t = 1;
        else t = 0;
        if(mov<k)
            best = max(best, go(idx + 1, mov + 1, t) + 1);
        best = max(best, go(idx + 1, mov, cur));
    }
    vis[idx][mov][cur] = true;
    dp[idx][mov][cur] = best;
    return best;

}

int main() {
    cin >> n >> k;
    cin >> str;

    // Please write your code here.
    cout << go(0, 0, 0);
    return 0;
}
//2개의 샘터 수정-->샘터에서 생성 공중에서 잡아야한다
//두 샘터사이를 최대 K번만 이동
//두 샘터중 한곳에 떨어진다 각 시간마다
//해당샘터앞에 있을때 수정 수집 가능
//N개의 수정이 생성
//초기에는 왼쪽
