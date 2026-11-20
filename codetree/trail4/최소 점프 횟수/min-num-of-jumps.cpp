#include <iostream>

using namespace std;

int n;
int num[10];

int ans = 1e9;

void go(int idx, int count) { //idx는 현재 위치
    if (count > ans) return;
    if (idx >= n - 1) {
        ans = min(ans, count);
        return;
    }
    int dist_can = num[idx]; //갈수있는 최대
    for (int i = 1; i <= dist_can; i++) {
        int temp = idx;
        temp += i;
        go(temp, count + 1);
    }
    return;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    go(0, 0);
    if (ans == 1e9) cout << -1;
    else cout << ans;
    // Please write your code here.

    return 0;
}

//N개의 정수가 첫번째 위치부터 순서대로 주어진거야
//첫번째 위치부터 N번째 위치에 도달하기 위해 필요한 최소 점프 횟수
