#include <iostream>
#include<vector>
using namespace std;

int n, m;
int from[10000], to[10000];
vector<int> graph[10001];
bool vis[10001];

void dfs(int num) {
    if (vis[num]) return;
    vis[num] = true;
    for (int i = 0; i < graph[num].size(); i++) {
        int nxt = graph[num][i];
        dfs(nxt);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    // Please write your code here.
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (vis[i]) ans++;
    }
    cout << ans;
    return 0;
}
