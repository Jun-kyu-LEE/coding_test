#include <iostream>
#include<queue>
using namespace std;

int N;
int dist[1000001];

int main() {
    cin >> N;
    dist[N] = 1;
    queue<int> q;
    q.push(N);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == 1) break;
        if (cur % 2 == 0) {
            int nxt = cur / 2;
            if (dist[nxt] == 0) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
        if (cur % 3 == 0) {
            int nxt = cur / 3;
            if (dist[nxt] != 0) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        } if (cur - 1 >= 1) {
            int nxt = cur - 1;
            if (dist[nxt] == 0) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
        if (cur + 1 <= 2000000) {
            int nxt = cur + 1;
            if (dist[nxt] == 0) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
    // Please write your code here.
    cout << dist[1] - 1;
    return 0;
}
