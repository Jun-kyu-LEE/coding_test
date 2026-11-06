#include <iostream>

using namespace std;

int n, m;
int numbers[100];

void drop() {
    int temp[100];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] == 0) continue;
        else {
            temp[idx] = numbers[i];
            idx++;
        }
    }
    
    for (int i = 0; i < idx; i++) {
        numbers[i] = temp[i];
    }
    n = idx;
}

bool bomb() {
    bool explored = false;
    int count = 1;
    int st = 0, end = 0;
    for (int i = 1; i <= n; i++) {
        if (i < n && numbers[i] == numbers[i - 1]) {
            count++;
        }
        else {
            if (count >= m) {
                for (int k = st; k < i; k++) numbers[k] = 0;
                explored = true;
            }
            count = 1;
            st = i;
        }
    }
    drop();
    return explored;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    while (bomb());

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << "\n";
    }
    // Please write your code here.

    return 0;
}
