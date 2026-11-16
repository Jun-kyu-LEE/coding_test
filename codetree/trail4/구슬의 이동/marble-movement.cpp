#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int n, m, t, k;
int r[2500], c[2500];
char d[2500];
int v[2500];

int board[51][51];
bool check[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void remove() {
    //k개 이상인경우 제거하는 거

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (board[x][y] > k) {
                vector<pair<int, int>> re;
                for (int i = 0; i < m; i++) {
                    if (x == r[i] && y == c[i]) {
                        re.push_back({v[i], i});
                    }
                }
                sort(re.begin(), re.end());
                for (int count = 0; count < board[x][y] - k; count++) {
                    int t = re[count].second;
                    c[t] = -1; r[t] = -1;
                }
                board[x][y] = k;
            }
        }
    }

}

void move() {
    for (int i = 0; i < m; i++) {
        int dir = -1;
        if (c[i] == -1) continue;
        if (d[i] == 'R') {
            dir = 2;
        } else if (d[i] == 'L') {
            dir = 3;
        } else if (d[i] == 'U') {
            dir = 1;
        } else if (d[i] == 'D') {
            dir = 0;
        }
        int nr = r[i];
        int nc = c[i];

        for (int val = 0; val < v[i]; val++) {
            nr += dx[dir];
            nc += dy[dir];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                if (dir == 2) { dir = 3; d[i] = 'L'; }
                else if (dir == 3) { dir = 2; d[i] = 'R'; }
                else if (dir == 0) { dir = 1; d[i] = 'U'; }
                else if (dir == 1) { dir = 0; d[i] = 'D'; }
                nr = nr + 2 * dx[dir];
                nc = nc + 2 * dy[dir];
            }
        }
        board[nr][nc]++;
        board[r[i]][c[i]]--;
        r[i] = nr;
        c[i] = nc;
    }
}

int main() {
    cin >> n >> m >> t >> k; //시간 //각 칸에서 살아남을 최대 구슬 수

    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i] >> d[i] >> v[i];
        r[i]--; c[i]--;
        board[r[i]][c[i]]++;
    }
    //r,c에서 d방향으로 속도 v로 이동중

    // Please write your code here.
    for (int time = 1; time <= t; time++) {

        //방향만큼 이동시키기
        move();

        remove();

    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (r[i] == -1) continue;
        ans++;
    }
    cout << ans;
    return 0;
}
