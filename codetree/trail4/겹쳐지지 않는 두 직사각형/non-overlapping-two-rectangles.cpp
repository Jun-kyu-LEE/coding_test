#include <iostream>

using namespace std;

int n, m;
int grid[5][5];
bool vis[5][5];


int rectSum1(int x1, int y1, int x2, int y2) {
    int sum = 0;
    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++)
            {sum += grid[i][j]; vis[i][j]=true;}
    return sum;
}

int rectSum2(int x1, int y1, int x2, int y2) {
    int sum = 0;
    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++)
            {   if(vis[i][j]){return -1e9;}
                sum += grid[i][j];
                }
    return sum;
}

void init(int x1,int y1,int x2,int y2){
     for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++)
            { vis[i][j]=false;}
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int answer=-1e9;
    for(int i1=0; i1<n; i1++){
        for(int j1=0; j1<m; j1++){
            int sum1=-1e9;
            for(int i2=i1; i2<n; i2++){
                for(int j2=j1; j2<m; j2++){
                        sum1=rectSum1(i1,j1,i2,j2);
                        int sum2=0;
                        for(int x1=0; x1<n; x1++){
                            for(int y1=0; y1<m; y1++){
                                for(int x2=x1; x2<n; x2++){
                                    for(int y2=y1; y2<m; y2++){
                                        sum2=rectSum2(x1,y1,x2,y2);   
                                        if (sum2 == -1e9) continue;           // 겹치면 건너뛰기
                                        answer = max(answer, sum1 + sum2);    // 가장 안쪽에서 갱신  
                                    }
                                }
                            }
                        }
                        init(i1,j1,i2,j2);
                    
                }
            }
        }
    }
    // Please write your code here.
    cout<<answer;
    return 0;
}
