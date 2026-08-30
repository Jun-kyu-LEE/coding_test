#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		int diff[202] = { 0 };

		for (int i = 0; i < N; i++) {
			int a, b; cin >> a >> b;
			int s = (a + 1) / 2, e = (b + 1) / 2;
			if (s > e) swap(s, e);
			diff[s]++;          // 구간 시작에서 +1
			diff[e + 1]--;        // 구간 끝 다음에서 -1
		}

		int result = 0, cur = 0;
		for (int i = 1; i <= 200; i++) {
			cur += diff[i];             // 누적하면 그 칸의 인원수
			result = max(result, cur);
		}
		
		cout << "#" << tc << " " << result << "\n";


	}
}