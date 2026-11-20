#include <iostream>
#include<string>
using namespace std;

int n;
int arr[81];

bool check(int len) { // arr[0 ~ len-1]이 가능한가
    for (int L = 1; L * 2 <= len; L++) {
        bool same = true;
        for (int k = 0; k < L; k++) {
            if (arr[len - 2 * L + k] != arr[len - L + k]) { // 앞 덩어리 k번째 vs 뒤 덩어리 k번째
                same = false;
                break;
            }
        }
        if (same) return false; // 한 L이라도 같으면 불가능
    }
    return true;
}

bool go(int size) {
    if (size == n) {
        return true;
    }
    for (int num = 4; num <= 6; num++) {
        arr[size] = num;
        if (check(size + 1) && go(size + 1)) return true;
    }
    return false;
}

int main() {
    cin >> n;

    // Please write your code here.
    go(0);
    for (int i = 0; i < n; i++) cout << arr[i];
    return 0;
}
