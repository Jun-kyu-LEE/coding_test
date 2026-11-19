#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> v; //a b
bool check[15];

vector<int> move() {
    vector<int> result(n);
    for (int i = 0; i < n; i++) result[i] = i + 1;
    for (int i = 0; i < m; i++) {
        int a = v[i].second;
        swap(result[a - 1], result[a]);
    }
    return result;
}

vector<int> move2() {
    vector<int> result(n);
    for (int i = 0; i < n; i++) result[i] = i + 1;
    for (int i = 0; i < m; i++) {
        if (check[i]) continue;
        int a = v[i].second;
        swap(result[a - 1], result[a]);
    }
    return result;
}
int ans = 20;
void go(int idx) {
    //m개중 x개 고르는거지
    //사용불가능
    if (idx == m) {
        if (move() == move2()) {
            int sum = 0;
            for (int i = 0; i < m; i++) {
                if (!check[i]) sum++;
            }
            ans = min(ans, sum);
            return;
        }
        else return;
    }
    check[idx] = true;
    go(idx + 1);
    check[idx] = false;
    go(idx + 1);

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});

    }
    sort(v.begin(), v.end());
    go(0);
    cout << ans;
    // Please write your code here.

    return 0;
}

//사람수 N만큼 세로줄 긋고, 1~N
//세로줄 사이에 M개 긋기
//원래 결과랑 동일하게 나오는 최소 가로줄 구하기

//ai, bi i번째 가로줄이 왼쪽에서부터 a번째 가로줄가 ai+1번째 세로줄 b번째 위치에 그어진다
//1 1 --> 1번->2번 첫번째줄
//1 3 --> 1번-->2번 세번째줄
