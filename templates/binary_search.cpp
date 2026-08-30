// 이분탐색 — 값 찾기 / 파라메트릭 서치
#include <bits/stdc++.h>
using namespace std;

// ── 1. 값 찾기 ──────────────────────────────────
int lowerBound(const vector<int>& v, int target) {   // target 이상이 처음 나오는 위치
    int lo = 0, hi = (int)v.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
// STL: lower_bound(v.begin(), v.end(), x) - v.begin();

// ── 2. 파라메트릭 서치 ──────────────────────────
// "조건을 만족하는 최댓값/최솟값" → 답을 이분탐색한다.
bool possible(long long x) {
    // x 를 답으로 삼았을 때 조건을 만족하는가?
    return true;
}

long long parametricMax(long long lo, long long hi) {   // 만족하는 최댓값
    long long answer = lo;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (possible(mid)) { answer = mid; lo = mid + 1; }
        else               { hi = mid - 1; }
    }
    return answer;
}
