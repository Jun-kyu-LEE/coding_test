#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

int countGold(int r, int c, int k) {         
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (abs(i - r) + abs(j - c) <= k)
                cnt += grid[i][j];
    return cnt;
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    //금한개의 가격이 M이야
    // Please write your code here.
     int answer=0;
    for(int k=0; k<=n; k++){
       
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int gold = countGold(i, j, k);
                int cost = k * k + (k + 1) * (k + 1);
                if (gold * m >= cost)
                    answer = max(answer, gold);
            }
        }
    }
    cout<<answer;
    return 0;
}
//마름모 모양이야
//
//가운데에서 거리를 증가시키는 방향으로 
//k가 1일때는 마름모 모양 k==2일때는  큰 마름모 
//k=0일때는 그거야
//차원을 벗어난 채굴도 가능하다
//int k=0; k=1; k=2;