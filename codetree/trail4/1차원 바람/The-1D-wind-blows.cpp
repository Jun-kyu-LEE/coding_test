#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];

//함수 몇개 
//바람함수 (좌,우,index)
//위아래 체크
//

void shift(int r,char d){
    if(d=='L'){
        int temp=a[r][m-1];
        for(int i=m-1; i>=1; i--){
            a[r][i]=a[r][i-1];
        }
        a[r][0]=temp;
    }
    if(d=='R'){
        int temp=a[r][0];
        for(int i=1; i<m; i++){
            a[r][i-1]=a[r][i];
        }
        a[r][m-1]=temp;
    }
}
bool check(int r,int t){ //같은게 있으면 true 다 다르면 false;
    for(int i=0; i<m; i++){
        if(a[r][i]==a[t][i])return true;
    }
    return false;
}


int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d; //'L' 또는 'R'
        cin >> r >> d;
        r--;
        shift(r,d);
        //위 아래가 같읁 ㅣ확인
        //위부터 확인
        int up=r; //감소 시키기
        int down=r;
        
        char temp=d;
 
        while(up-1>=0&&check(up,up-1)){
            if(temp=='L')temp='R';
            else temp='L';            
            up=up-1;    
            shift(up,temp);
        }
        temp=d;

        while(down+1<n&&check(down,down+1)){
         
            if(temp=='L')temp='R';
            else temp='L';            
            down=down+1;
            shift(down,temp);
        }  
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    // Please write your code here.

    return 0;
}
//특정행들이 밀리면 위 아래로 영향 
//단 하나라도 같은 숫자가 있으면 전파를 이어간다
//같은 숫자가 존재하지않거나 끝까지 가면
//반대방향으로 한칸씩 밀기
//또 전파를 진행
//한번 하면 또 원래 반대방향으로 
