#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int NEG = -1e9;   // 불가능한 상태

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    int OFFSET = total;          // 차이 0이 저장될 위치
    int SIZE = 2 * total + 1;    // 차이 범위: -total ~ +total

    // dp[d] = 차이(A합 - B합)가 d - OFFSET일 때 가능한 가장 큰 A합
    vector<int> prev(SIZE, NEG), cur(SIZE);
    prev[OFFSET] = 0;            // 아무것도 안 넣음: 차이 0, A합 0

    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int d = 0; d < SIZE; d++) {
            int best = prev[d];                                  // 버리기 (C)
            if (d - x >= 0 && prev[d - x] != NEG)
                best = max(best, prev[d - x] + x);               // A에 넣기
            if (d + x < SIZE && prev[d + x] != NEG)
                best = max(best, prev[d + x]);                   // B에 넣기
            cur[d] = best;
        }
        prev = cur;              // 이번 수 처리 끝 → 다음 수의 이전 상태로
    }

    cout << prev[OFFSET];        // 차이 0 = A합과 B합이 같을 때
    return 0;
}