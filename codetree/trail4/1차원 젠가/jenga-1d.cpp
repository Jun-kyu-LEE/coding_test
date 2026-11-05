#include <iostream>

using namespace std;

int n;
int blocks[100];
int s1, e1;
int s2, e2;
int idx;
void drop(int s1, int e1) {
    for (int i = s1; i <= e1; i++) blocks[i] = -1;
    int temp[100];

    idx = 0;
    for (int i = 0; i < n; i++) {
        if (blocks[i] == -1) continue;
        else {
            temp[idx] = blocks[i];
            idx++;
        }
    }

    for (int i = 0; i < idx; i++) {
        blocks[i] = temp[i];
    }
    n = idx;

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }
    cin >> s1 >> e1;
    drop(s1 - 1, e1 - 1);
    cin >> s2 >> e2;
    drop(s2 - 1, e2 - 1);

    cout << idx << "\n";

    for (int i = 0; i < idx; i++) {
        if (blocks[i] == -1) continue;
        cout << blocks[i] << "\n";
    }
    // Please write your code here.

    return 0;
}
