#include<iostream>
using namespace std;

int board[11]; //board[i]-->i번째 row에 놓인 col값 
int N;
int result = 0;

bool check(int col, int row) {
	for (int i = 0; i < row; i++) {
		if (board[i] == col)return false;
		if (abs(board[i] - col) == abs(i - row))return false;
	}
	return true;
}

void back(int row) {
	if (N == row) {
		result++;
		return;
	}

	for (int col = 0; col < N; col++) {
		if (check(col, row)) {
			board[row] = col;
			back(row + 1);
			board[row] = -1;
		}
	}

}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		cin >> N;
		for (int i = 0; i < N; i++)board[i] = -1;
		result = 0;
		back(0);
		cout << "#" << tc << " " << result << "\n";
	}
}