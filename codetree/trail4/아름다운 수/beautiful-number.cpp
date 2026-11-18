#include <iostream>

using namespace std;

int n;
int ans=0;
void go(int size){
    if(size==n){
        ans++;
        return;
    }
    if(size>n)return;

    for(int i=1; i<=4; i++){
        go(size+i);
    }
}

int main() {
    cin >> n;
    ans=0;
    go(0);
    // Please write your code here.
    cout<<ans;
    return 0;
}

//정확히 해당 숫자만큼 연달아 같은 숫자가 나오는 수
//1은 한번 2는 두번 3은 세번 4는 네번 나와야하는거야
