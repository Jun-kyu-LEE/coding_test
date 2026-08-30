#include<iostream>
#include<vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		int N, L;
		cin >> N >> L;
		vector<int>dp(L+1, 0);
		vector<int>score(N, 0);
		vector<int>cal(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> score[i] >> cal[i];
		}
		for (int i = 0; i < N; i++) {

			for (int j = L; j >= cal[i]; j--) {
				dp[j] = max(dp[j], dp[j - cal[i]] + score[i]);
			}

		}
		cout << "#" << tc << " " << dp[L];

	}
}