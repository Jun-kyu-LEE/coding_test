#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int a[15], b[15];
vector<pair<int, int>> v;

bool isused[16];

vector<int> move() {
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        int a = v[i].second;
        swap(result[a - 1], result[a]);
    }
    return result;
}

vector<int> move2() {
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        int a = v[i].second;
        if (isused[i]) continue; //사용안하는건 true로 표시
        swap(result[a - 1], result[a]);
    }
    return result;
}
int ans = 20;
void go(int idx) {
    if (idx == m) {
        if (move() == move2()) {
            int sum = 0;
            for (int i = 0; i < m; i++) if (!isused[i]) sum++;
            ans = min(ans, sum);
        }
        return;
    }

    go(idx + 1);
    isused[idx] = true;
    go(idx + 1);
    isused[idx] = false;
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
    // Please write your code here.
    cout << ans;
    return 0;
}
