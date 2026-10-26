#include <iostream>

using namespace std;

int n;
int first_cards[1000];
int second_cards[1000];
bool vis[1000][1000];
long long memo[1000][1000];

int result=-1;

const long long NEG=-1e18;

long long go(int first,int second){
    if(first==n||second==n){
       return 0;
    }
    if(vis[first][second])return memo[first][second];

    long long best=NEG;

    if(first_cards[first]<second_cards[second]){
        best=max(best,go(first+1,second));
    }
    else if(first_cards[first]>second_cards[second]){
        best=max(best,go(first,second+1)+second_cards[second]);
    }
    best=max(best,go(first+1,second+1));
    vis[first][second]=true;
    memo[first][second]=best;
    return best;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> first_cards[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> second_cards[i];
    }

    // Please write your code here.
    cout<<go(0,0);
    return 0;
}
