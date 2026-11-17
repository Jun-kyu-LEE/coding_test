#include <iostream>

using namespace std;

int T;
int N;
int x[100];
int y[100];
int w[100];
char d[100];

int board[2001][2001];
int dx[4] = {0, 0, 1, -1}; // D U R L
int dy[4] = {-1, 1, 0, 0};
bool flag = false;

void move() {
    int nx[100], ny[100];
    for (int i = 0; i < N; i++) {
        int dir = -1;
        if (x[i] == 9999) continue;
        if (d[i] == 'R') {
            dir = 2;
        } else if (d[i] == 'L') {
            dir = 3;
        } else if (d[i] == 'U') {
            dir = 1;
        } else if (d[i] == 'D') {
            dir = 0;
        }
        nx[i] = x[i] + dx[dir];
        ny[i] = y[i] + dy[dir];
    }

    for (int i = 0; i < N; i++) {
        if (x[i] == 9999) continue;
        for (int j = i + 1; j < N; j++) {
            if (x[j] == 9999) continue;
            if (nx[i] == x[j] && ny[i] == y[j] && nx[j] == x[i] && ny[j] == y[i]) {

                flag = true;
                if (w[j] > w[i]) {
                    x[i] = 9999;
                    y[i] = 9999;
                }
                else if (w[j] == w[i]) {
                    if (j > i) {
                        x[i] = 9999;
                        y[i] = 9999;
                    }
                    else {
                        x[j] = 9999;
                        y[j] = 9999;
                    }
                } else {
                    x[j] = 9999;
                    y[j] = 9999;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (x[i] == 9999) continue;
        if (nx[i] < -1000 || nx[i] > 1000 || ny[i] < -1000 || ny[i] > 1000) { x[i] = 9999; y[i] = 9999; continue; }
        x[i] = nx[i]; y[i] = ny[i];
    }
}

void remove() {
    for (int i = 0; i < N; i++) {
        if (x[i] == 9999) continue;
        int &cell = board[x[i] + 1000][y[i] + 1000];
        if (cell == 0) { cell = i + 1; continue; }
        int j = cell - 1;
        flag = true;
        if (w[i] > w[j] || (w[i] == w[j] && i > j)) { x[j] = 9999; y[j] = 9999; cell = i + 1; }
        else { x[i] = 9999; y[i] = 9999; }
    }
    for (int i = 0; i < N; i++)
        if (x[i] != 9999) board[x[i] + 1000][y[i] + 1000] = 0;

}

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> x[i] >> y[i] >> w[i] >> d[i];

        }
        //n이 구슬의 개수야
        //x,y좌표 w 가중치 d방향

        int ans = -1;
        int time = 0;
        flag = false;
        while (1) {
            time++;
            move();
            if (flag) ans = time;
            flag = false;
            time++;
            remove();
            if (flag) ans = time;
            flag = false;
            int alive = 0;
            for (int i = 0; i < N; i++) if (x[i] != 9999) alive++;
            if (alive <= 1 || time >= 4000) break;

        }
        cout << ans << "\n";
        // Please write your code here.

    }

    return 0;
}
//충돌을 어떻게 할꺼냐
//한번에
//모두 2초에 한칸씩 동일한 속도야
//두개 이상의 구슬이 충돌하게되면 하나의 구술만 남게된다
//이동하는 도중에 발생할수도있어
//더이상 충돌이 안일어난다 이걸 어케알지 그냥 무식하게 2000번 반복?
