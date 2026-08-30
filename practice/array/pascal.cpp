#include<iostream>

using namespace std;

int main() {
	
	int board[11][11];
	for (int i = 1; i <= 10; i++) {
		board[i][1] = 1;
		board[i][i] = 1;
	}
	for (int i = 2; i <= 10 - 1; i++) {
		for (int j = 2; j <= 10 - 1; j++) {
			board[i][j] = board[i - 1][j - 1] + board[i - 1][j];
		}
	}
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		
		cout << "#" << tc << "\n";
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= i; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}

	}
}