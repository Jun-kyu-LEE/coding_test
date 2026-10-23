#include <iostream>

using namespace std;

int n;
int coin[1001];

int dp[1001][4];
const int NEG=-1e9;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }
   
    for (int i = 0; i <= n; i++)
    for (int j = 0; j < 4; j++)
         dp[i][j] = NEG;          // 1. 전부 불가능
dp[0][0] = 0;                    // 2. 땅에서 출발

for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 4; j++) {
        // 2칸 점프로 옴
        if (i >= 2 && dp[i-2][j] != NEG)                    // 3. 불가능하면 건너뜀
            dp[i][j] = max(dp[i][j], dp[i-2][j] + coin[i]);
        // 1칸으로 옴
        if (j >= 1 && dp[i-1][j-1] != NEG)
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + coin[i]);
    }
}

    int result=-1;
    for(int i=0; i<4; i++)result=max(result,dp[n][i]);
    cout<<result;
    return 0;
}
