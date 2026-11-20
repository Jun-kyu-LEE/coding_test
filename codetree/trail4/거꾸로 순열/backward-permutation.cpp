#include <iostream>

using namespace std;

int n;
bool vis[10];
int arr[8];

void go(int idx) {

    if (idx == n) {
        for (int i = 0; i < idx; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = n; i >= 1; i--) {
        if (vis[i] == true) continue;
        arr[idx] = i;
        vis[i] = true;
        go(idx + 1);
        vis[i] = false;
    }
}

int main() {
    cin >> n;
    go(0);
    // Please write your code here.

    return 0;
}
