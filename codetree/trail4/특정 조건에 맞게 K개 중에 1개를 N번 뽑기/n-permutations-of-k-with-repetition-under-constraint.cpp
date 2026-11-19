#include <iostream>

using namespace std;

int K, N;
int arr[8];

void go(int idx, int num, int count) {

    if (count == 3) return;
    if (idx == N) {

        for (int i = 0; i < idx; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= K; i++) {
        arr[idx] = i;
        if (num == i) {
            go(idx + 1, i, count + 1);
        } else {
            go(idx + 1, i, 1);
        }
    }
}

int main() {
    cin >> K >> N;

    // Please write your code here.
    go(0, -1, 0);
    return 0;
}
//K이하의 정수를 하나 고르는 행위 N번 반복
//같은 정수가 3번이상이면 제외
