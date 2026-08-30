//이분탐색 문제라는데 시발 왜 그러지


#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        long long N, M;
        cin >> N >> M;

        vector<long long> t(N);
        for (int i = 0; i < N; i++) {
            cin >> t[i];
        }
        sort(t.begin(), t.end());
        // 이분탐색 범위 설정
        long long low = t[0];   // 힌트: 가장 빠른 심사대(t 중 최솟값)로 1명 심사하는 시간
        long long high = M*t[N-1];  // 힌트: 가장 느린 심사대(t 중 최댓값) 하나로 M명을 전부 심사한다면?

        // 이분탐색: "X초 안에 M명 이상 심사 가능한 최소 X"를 찾는다
        while (low < high) {
            long long mid = low + (high - low) / 2; // 오버플로우 방지용 중간값 계산

            // mid초 동안 모든 심사대가 처리할 수 있는 사람 수의 합을 구한다
            long long count = 0;
            for (int i = 0; i < N; i++) {
                count += mid/t[i];  // 힌트: 심사대 i가 mid초 동안 몇 명을 심사할 수 있는지 (나눗셈 한 줄)
                if (count >= M)break;
            }

            if (count >= M) {
                // mid초면 충분하다 -> 더 작은 값도 가능한지 확인해야 하니
                high =mid;
            }
            else {
                // mid초로는 부족하다 -> 더 큰 값을 시도해야 하니
                low = mid+1;
            }
        }

        cout << "#" << tc << " " << low << "\n";
    }
}