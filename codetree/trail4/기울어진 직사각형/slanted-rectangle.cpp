#include <iostream>

using namespace std;

int n;
int grid[20][20];

int dx[4]={-1,-1,1,1};
int dy[4]={1,-1,-1,1};



int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int answer=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int sum=grid[i][j];
            
            for(int k=1; k<n; k++){
                for(int l=1; l<n; l++){
                    int move_num[4]={k,l,k,l};
                    int x=i; int y=j;
                    int sum=0;

                    bool check=true;

                    for(int dir=0; dir<4&&check; dir++){
                        for(int s=0; s<move_num[dir]; s++){//얼마나갈껀지를 정해놓을수있어
                            x=x+dx[dir];
                            y=y+dy[dir];
                            if(x<0||x>=n||y<0||y>=n){check=false; break;}
                            sum+=grid[x][y];
                        }
                    }
                    if(check)answer=max(answer,sum);

                }
            }
        }
    }
    // Please write your code here.
    cout<<answer;
    return 0;
}
//대각선으로 움직이면서 반시계 순회를 했을때 지나왔던 집합 
//길이를 어케해야할지 그걸 생각해보자
//일단 대각선으로 움직이는건 다 할수있어
//일단 다 양수니까 최대한 많은게 다 좋아 
//그러면 
//k,l을 정하면 나머지가 다 정해진다 시작점이랑 
//k는 2부터 N-1까지 해보면 되려나 그냥 
//k+l=N+1이여야하지