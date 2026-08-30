

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int result = 0;
int N, B;
vector<int> H(21);

void dfs(int idx, int sum) {
	if (sum >= result) return;    // 이미 답보다 크면 볼 필요 없음
	if (sum >= B) { result = sum; return; }   // 더 더하면 손해
	if (idx == N) return;
	dfs(idx + 1, sum + H[idx]);
	dfs(idx + 1, sum);
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		cin >> N >> B;
	
		int sum = 0;
		for (int i = 0; i < N; i++) {
			cin >> H[i];
		}
		result = 987654321;
		dfs(0, 0);
		result = result-B;
		cout << "#" << tc << " " << result << "\n";



	}
}