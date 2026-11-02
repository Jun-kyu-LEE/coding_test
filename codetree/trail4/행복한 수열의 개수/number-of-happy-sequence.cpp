#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int answer=0;
    for(int i=0; i<n; i++){
        
        int temp=1;
        int temp2=0;
      for(int j=1; j<n; j++){
        if(grid[i][j]==grid[i][j-1])temp++;
        else {
            temp2=max(temp2,temp);
            temp=1;
            }
      }
       temp2=max(temp2,temp);
      if(temp2>=m)answer++;
    }

    for(int i=0; i<n; i++){
        
        int temp=1;
        int temp2=0;
      for(int j=1; j<n; j++){
        if(grid[j][i]==grid[j-1][i])temp++;
        else {
            temp2=max(temp2,temp);
            temp=1;
            }
      }
      temp2=max(temp2,temp);
      if(temp2>=m)answer++;
    }

    cout<<answer;


    // Please write your code here.

    return 0;
}
