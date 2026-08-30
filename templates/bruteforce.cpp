// 완전탐색 3종: 부분집합 / 순열 / 조합
// 삼성 SW 역량테스트·SWEA 고득점 문제의 절반은 여기서 시작한다.
#include <bits/stdc++.h>
using namespace std;

int N;
int arr[20];

// ── 1. 부분집합 (2^N) ───────────────────────────
// 각 원소를 "고른다 / 안 고른다"
int pick[20];
void subset(int idx, int cnt) {
    if (idx == N) {
        // pick[0..cnt-1] 이 선택된 부분집합
        return;
    }
    pick[cnt] = arr[idx];
    subset(idx + 1, cnt + 1);   // 포함
    subset(idx + 1, cnt);       // 미포함
}

// 비트마스크 버전 (N <= 20 권장)
void subsetBit() {
    for (int mask = 0; mask < (1 << N); ++mask) {
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                // arr[i] 선택됨
            }
        }
    }
}

// ── 2. 순열 (N!) — 순서가 의미 있을 때 ──────────
bool used[20];
int perm[20];
void permutation(int depth) {
    if (depth == N) {
        // perm[0..N-1] 완성
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (used[i]) continue;
        used[i] = true;
        perm[depth] = arr[i];
        permutation(depth + 1);
        used[i] = false;        // 백트래킹
    }
}

// STL 버전 — 반드시 정렬된 상태에서 시작할 것
void permutationSTL() {
    sort(arr, arr + N);
    do {
        // arr 이 현재 순열
    } while (next_permutation(arr, arr + N));
}

// ── 3. 조합 (nCr) — 순서 무관 ───────────────────
int comb[20];
void combination(int start, int depth, int r) {
    if (depth == r) {
        // comb[0..r-1] 완성
        return;
    }
    for (int i = start; i < N; ++i) {
        comb[depth] = arr[i];
        combination(i + 1, depth + 1, r);
    }
}
