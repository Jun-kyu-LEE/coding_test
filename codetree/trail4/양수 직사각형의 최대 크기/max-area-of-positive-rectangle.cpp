#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

bool check(int x1,int y1,int x2,int y2){
    for(int i=x1; i<=x2; i++){
        for(int j=y1; j<=y2; j++){
            if(grid[i][j]<=0)return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int answer=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int size=0;
            for(int x=i; x<n; x++){
                for(int y=j; y<m; y++){
                    if(check(i,j,x,y)){
                       size=(x-i+1)*(y-j+1);
                       answer=max(answer,size); 
                    }
                }
            }
        }
    }
    cout<<answer;

    // Please write your code here.

    return 0;
}
