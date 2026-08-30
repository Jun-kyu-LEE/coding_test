// SWEA 기본 틀
// ⚠ 제출 전 freopen 줄이 주석 처리되어 있는지 반드시 확인!
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);   // 로컬 테스트용. 제출 시 주석!

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        // ── 입력 ──

        // ── 풀이 ──
        int answer = 0;

        // ── 출력 (SWEA 형식: #테스트케이스번호 답) ──
        cout << '#' << tc << ' ' << answer << '\n';
    }
    return 0;
}
