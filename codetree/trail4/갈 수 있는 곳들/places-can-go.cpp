#include <iostream>
#include<queue>
using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
bool vis[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        queue<pair<int, int>> q;
        r[i]--;
        c[i]--;
        q.push({r[i], c[i]});
        vis[r[i]][c[i]] = true;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (grid[nx][ny] == 1 || vis[nx][ny] == true) continue;
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
    int result=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)if(vis[i][j])result++;
    }
    // Please write your code here.
    cout<<result;
    return 0;
}
