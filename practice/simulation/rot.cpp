#include<iostream>
using namespace std;


void rot(int N) {

}


int main() {
	int T;
	cin >> T;
	int board[8][8];
	int rotaed1[8][8];
	int rotaed2[8][8];
	int rotaed3[8][8];

	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cin >> board[i][j];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				rotaed1[j][N - 1 - i] = board[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				rotaed2[j][N - 1 - i] = rotaed1[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				rotaed3[j][N - 1 - i] = rotaed2[i][j];
			}
		}




	}
}