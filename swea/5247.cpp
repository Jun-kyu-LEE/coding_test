#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dist[1000001];

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, M;
        cin >> N >> M;

        memset(dist, -1, sizeof(dist));

        queue<int> q;
        q.push(N);
        dist[N] = 0;

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (cur == M) break;

            int nxt[4] = { cur + 1, cur - 1, cur * 2, cur - 10 };
            for (int i = 0; i < 4; i++) {
                int nx = nxt[i];
                if (nx < 1 || nx > 1000000) continue;
                if (dist[nx] != -1) continue;
                dist[nx] = dist[cur] + 1;
                q.push(nx);
            }
        }

        cout << "#" << tc << " " << dist[M] << "\n";
    }
}