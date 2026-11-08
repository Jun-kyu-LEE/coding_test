#include <iostream>

using namespace std;

int N, M, K;
int numbers_2d[100][100];

void drop() {
    for (int j = 0; j < N; j++) {
        int idx = 0;
        int temp[100];
        for (int i = 0; i < N; i++) {
            if (numbers_2d[i][j] == 0) continue;
            temp[idx] = numbers_2d[i][j];
            idx++;
        }

        for (int i = 0; i < idx; i++) {
            numbers_2d[N - 1 - i][j] = temp[idx - 1 - i];
        }

        for (int i = idx; i < N; i++) numbers_2d[N - 1 - i][j] = 0;

    }

}

void dropCol(int j) {
    int idx = 0;
    int temp[100];
    for (int i = 0; i < N; i++) {
        if (numbers_2d[i][j] == 0) continue;
        temp[idx] = numbers_2d[i][j];
        idx++;
    }
    for (int i = 0; i < idx; i++) numbers_2d[N - 1 - i][j] = temp[idx - 1 - i];
    for (int i = idx; i < N; i++) numbers_2d[N - 1 - i][j] = 0;
}

bool bomb(int col) {
    bool explored = false;
    int count = 1;
    int st = 0, end = 0;
    for (int i = 1; i <= N; i++) {
        if (i < N && numbers_2d[i][col] == numbers_2d[i - 1][col]) {
            count++;
        }
        else {
            if (count >= M && numbers_2d[i - 1][col] != 0) {
                for (int k = st; k < i; k++) numbers_2d[k][col] = 0;
                explored = true;
            }
            count = 1;
            st = i;
        }
    }
    dropCol(col);
    return explored;
}

void rotateCW() {
    int temp[200][200];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[j][N - 1 - i] = numbers_2d[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            numbers_2d[i][j] = temp[i][j];
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> numbers_2d[i][j];
        }
    }

    for (int k = 0; k < K; k++) {
        //모든줄 터트리기
        for (int i = 0; i < N; i++) {
            while (bomb(i));
        }
        //회전하기
        rotateCW();
        drop();
    }
    // Please write your code here.
    for (int i = 0; i < N; i++) while (bomb(i));
    drop();
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (numbers_2d[i][j] != 0) answer++;
        }

    }
    cout << answer;
    return 0;
}

//구현
//1.위아래로 같은거 폭파
//2. 시계방향 회전
//3.반복
//
