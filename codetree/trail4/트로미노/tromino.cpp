#include <iostream>

using namespace std;

int n, m;
int grid[200][200];

int dx[4]={1,1,-1,-1};
int dy[4]={-1,1,-1,1};


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    //block모양 2개 
    //일단 
    // Please write your code here.
    int result=-1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            
            for(int dir=0; dir<4; dir++){
                int temp=grid[i][j];
                int nx=i+dx[dir];
                int ny=j+dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=m)continue;
                temp=temp+grid[nx][j]+grid[i][ny];
                result=max(result,temp);
            }
            

            int sum=grid[i][j];

             for(int k=1; k<=2; k++){
                if(i+2>=n)break;
                sum+=grid[i+k][j];
             }
             result=max(result,sum);
            sum=grid[i][j];

            for(int k=1; k<=2; k++){
                if(j+2>=m)break;
                sum+=grid[i][j+k];
            }
            result=max(result,sum);
        }
    }
    cout<<result;
    return 0;
}
