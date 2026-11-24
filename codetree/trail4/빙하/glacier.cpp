#include <iostream>
#include <queue>
using namespace std;

int N, M;
int a[200][200];
bool iswater[200][200];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int temp[200][200];
int cnt = 0;

void bfs() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) iswater[i][j] = false;

    queue<pair<int, int>> q;
    q.push({0, 0});
    iswater[0][0] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (a[nx][ny] == 1 || iswater[nx][ny] == true) continue;
            q.push({nx, ny});
            iswater[nx][ny] = true;
        }
    }
}

void melt() {
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 1) {
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (iswater[nx][ny] == true) {
                        temp[i][j] = 0;
                        cnt++;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            a[i][j] = temp[i][j];
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            temp[i][j] = a[i][j];
        }

    int time = 0;
    int last = 0; 
    while (1) {
        bfs(); 
        melt();
        if (cnt == 0) break; 
        time++;
        last = cnt;
    }
    cout << time << " " << last;
    return 0;
}
