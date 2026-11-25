#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int n, k, u, d;
int grid[8][8];
bool vis[8][8];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> chosen;
int result = 0;

int bfs() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) vis[i][j] = false;

    queue<pair<int, int>> q;
    for (int idx : chosen) { // 고른 시작점 전부
        int x = idx / n, y = idx % n;
        if (vis[x][y]) continue;
        vis[x][y] = true;
        q.push({x, y});
    }

    int cnt = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        cnt++;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny]) continue;
            int diff = abs(grid[x][y] - grid[nx][ny]);
            if (diff < u || diff > d) continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return cnt;
}

void go(int idx, int count) {
    if (count == k) {
        result = max(result, bfs());
        return;
    }
    for (int i = idx; i < n * n; i++) {
        chosen.push_back(i);
        go(idx + 1, count + 1);
        chosen.pop_back();
    }
}

int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    go(0, 0);

    //아 뭔가 잘짜고싶은데
    //시작점을 어케 다 넣을수가있을까
    cout << result;
    // Please write your code here.

    return 0;
}

//높이정보+K개의 도시
//높이차이가 U이상 D이하인 경우만 이동가능
//K개의 도시를 적절하게 골라 갈수있는 도시의수 최대
