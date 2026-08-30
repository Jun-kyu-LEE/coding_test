#include<iostream>
#include<queue>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int board[1001][1001];
int px[1000001];
int py[1000001];

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		
		vector<int>dp(N * N+1, -1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
				int value = board[i][j];
				px[value] = i;
				py[value] = j;
			}
		}
		int index = N * N;
		dp[index] = 1;

		int result = dp[index];
		int startV = index;

		for (int i = index - 1; i >= 1; i--) {
			bool flag = false;
			
			for (int dir = 0; dir < 4; dir++) {
				int nx = px[i] + dx[dir];
				int ny = py[i] + dy[dir];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
				if (board[nx][ny] == i + 1) {
					flag = true;
					break;
				}
			}
			if (flag)dp[i] = dp[i + 1] + 1;
			else dp[i] = 1;
			
			if (dp[i] >= result) {
				result = dp[i];
				startV = i;
			}

		}
		cout << "#" << tc << " " <<startV <<" " << result << "\n";


	}
}