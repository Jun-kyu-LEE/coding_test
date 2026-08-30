// 시뮬레이션 유틸 — 배열 회전, 방향 전환
// SWEA 모의 SW 역량테스트 유형에서 자주 쓰인다.
#include <bits/stdc++.h>
using namespace std;

// ── 2차원 배열 90도 시계방향 회전 ───────────────
vector<vector<int>> rotate90(const vector<vector<int>>& a) {
    int n = (int)a.size(), m = (int)a[0].size();
    vector<vector<int>> r(m, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            r[j][n - 1 - i] = a[i][j];
    return r;
}

// ── 방향 전환 ───────────────────────────────────
// 상, 우, 하, 좌 (시계방향으로 정렬해두면 회전이 쉬워진다)
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

inline int turnRight(int d) { return (d + 1) % 4; }
inline int turnLeft(int d)  { return (d + 3) % 4; }
inline int turnBack(int d)  { return (d + 2) % 4; }

// 대각선 포함 8방향이 필요할 때
const int dy8[8] = {-1, -1, 0, 1, 1,  1,  0, -1};
const int dx8[8] = { 0,  1, 1, 1, 0, -1, -1, -1};
