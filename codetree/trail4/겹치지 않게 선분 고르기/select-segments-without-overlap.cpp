#include <iostream>
#include<vector>
using namespace std;

int n;
int x1[15], x2[15];

int ans = -1;
void go(int idx, int count, vector<bool> check) {
    if (idx == n) {
        ans = max(ans, count);
        return;
    }
    //간단하게 선택할지 안할지를 결정하면 되는거잖아

    go(idx + 1, count, check); //선택 X

    vector<bool> nxt = check;
    for (int st = x1[idx]; st <= x2[idx]; st++) {
        if (nxt[st] == true) return;
        nxt[st] = true;
    }

    go(idx + 1, count + 1, nxt); //선택 O

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }
    vector<bool> t(1001, false);
    go(0, 0, t);
    // Please write your code here.
    cout << ans;
    return 0;
}
//N개중에서 겹치지않고 고를수있는 많은 선분의 수
//끝점을 공유하면 겹친거야
