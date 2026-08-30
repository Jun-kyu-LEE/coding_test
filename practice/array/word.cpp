#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    int board[16][16];

    for (int test_case = 1; test_case <= T; test_case++) {
        int N, K;
        cin >> N >> K;

        // 보드 입력 (1-indexed)
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> board[i][j];
            }
        }

        int temp = 0; // 들어갈 수 있는 자리의 수

        // 1. 가로 방향 검사
        for (int i = 1; i <= N; i++) {
            int count = 0; // 연속된 1의 길이
            for (int j = 1; j <= N; j++) {
                if (board[i][j] == 1) {
                    count++; // 1을 만나면 길이 증가
                }
                else {
                    // 0을 만났을 때, 지금까지 연속된 1의 길이가 정확히 K인지 확인
                    if (count == K) temp++;
                    count = 0; // 길이 초기화
                }
            }
            // 줄이 끝났을 때(벽에 닿았을 때), 마지막으로 누적된 길이가 K인지 확인
            if (count == K) temp++;
        }

        // 2. 세로 방향 검사
        for (int j = 1; j <= N; j++) {
            int count = 0; // 연속된 1의 길이
            for (int i = 1; i <= N; i++) {
                if (board[i][j] == 1) {
                    count++;
                }
                else {
                    if (count == K) temp++;
                    count = 0;
                }
            }
            if (count == K) temp++;
        }

        cout << "#" << test_case << " " << temp << "\n";
    }
    return 0;
}