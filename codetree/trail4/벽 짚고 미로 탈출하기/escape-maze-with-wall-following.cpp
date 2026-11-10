#include <iostream>

using namespace std;

int N;
int x, y;
char grid[101][101];
bool vis[101][101][4];
int dx[4]={0,-1,0,1}; //우 상 좌 하
int dy[4]={1,0,-1,0};
//벽은 하 우 상 좌 
//dir+3

int main() {
    cin >> N;
    cin >> x >> y;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }
    int result=1;
    int dir=0; //이동하고자하는 방향
    int wall_dir=3;
    
    while(1){
        if(vis[x][y][dir]==1){result=-1; break;}
        vis[x][y][dir]=true;
        //if(result>=N*N){result=-1; break;}
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if(nx<=0||nx>N||ny<=0||ny>N){break;}
        if(grid[nx][ny]=='#'){ //이동하지 못한 경우
            dir++;
            dir%=4;
        
            continue;
        }else{ //이동한 경우
            x=nx;
            y=ny;
            result++;
            int wall_dir=(dir+3)%4;

            int wall_x=x+dx[wall_dir];
            int wall_y=y+dy[wall_dir];
            if(grid[wall_x][wall_y]!='#'){
                dir--;
                if(dir==-1)dir=3;
                int nx2=x+dx[dir];
                int ny2=y+dy[dir];
                 if(nx2<=0||nx2>N||ny2<=0||ny2>N){break;}
                x=nx2;
                y=ny2;
                result++;
            }
        }
    }
    cout<<result;
    return 0;
}
//이동할때만 1초의 시간이 걸려
//걸리는 시간 출력 
//불가능하다면 -1출력


//오른쪽보고 시작,오른쪽 벽을 짚고 이동
//1)불가능하면 방향 바꾸기 우 상 좌 하   벽 하,우,상,좌
//2)가능하면 움직이기 -->격자 밖이면 탈출
//3)오른쪽에 벽이 있으면 그 쪽으로 이동 
//4)벽이 없으면 시계방향으로 돌리기
