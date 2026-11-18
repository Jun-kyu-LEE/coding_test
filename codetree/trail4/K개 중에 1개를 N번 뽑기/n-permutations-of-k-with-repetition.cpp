#include <iostream>

using namespace std;

int K, N;

int arr[10];
bool vis[10];

void go(int idx) {
    if (idx == N) {
        for (int i = 0; i < idx; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int num = 1; num <= K; num++) {
        arr[idx] = num;
        go(idx + 1);
    }
}
int main() {
    cin >> K >> N;

    // Please write your code here.
    go(0);

    return 0;
}
