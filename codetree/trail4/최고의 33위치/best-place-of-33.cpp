#include <iostream>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    int result=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int temp=0;
            for(int a=0; a<3; a++){
                for(int b=0; b<3; b++){
                    if(i+a>=N||j+b>=N)continue;
                    if(grid[i+a][j+b]==1)temp++;
                }
            }
        result=max(result,temp);

        }
    }
    cout<<result;
    // Please write your code here.

    return 0;
}
