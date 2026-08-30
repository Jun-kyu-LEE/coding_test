#include<iostream>
using namespace std;
int board[16][16];
int main() {
	int T;
	cin >> T;
	
	for (int test_case = 1; test_case <= T; test_case++) {
		int result = -1;
		int N, M;
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)cin >> board[i][j];
		}
		int size = M - 1;
		
		for (int i = 1; i <= N-size; i++) {
			for (int j = 1; j <= N-size; j++) {
				int sum = 0;
				for (int a = 0; a < M; a++) {
					for (int b = 0; b < M; b++) {
						sum += board[i + a][j + b];
					}
				}
				result = max(result, sum);

			}
		}


		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}