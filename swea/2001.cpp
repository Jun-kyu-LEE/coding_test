#include<iostream>
using namespace std;


int main() {
	int T;
	cin >> T;
	int board[16][16] = { 0, };
	int psum[17][17] = { 0, };
	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> board[i][j];
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				psum[i][j] =board[i][j]+ psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
			}
		}
		int result = -1;
		
		//i,j~~ i+M-1,j,M-1 까지의 합이 가장 큰거 찾으면 되는거잖아
		//0,0~1,1 
		for (int i = M; i <= N; i++) {
			for (int j = M; j <= N; j++) {
				int sum = psum[i][j] - psum[i - M][j] - psum[i][j - M] + psum[i - M][j - M];
				result = max(result, sum);
			}
		}
		cout << "#" << tc << " " << result << "\n";

	}
}