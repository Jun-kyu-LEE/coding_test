#include<iostream>
using namespace std;
int chess[10]; //-->row[i]=x  i번째 row에 x번째 col에 놓은거야.
bool vis[10];
int N;
int result = 0;

bool ischeck(int col, int row) {
	for (int i = 0; i < row; i++) {
		if (chess[i] == col)return false;
		if (abs(chess[i] - col) == abs(i - row))return false;
	}
	return true;
}

void back(int row) {
	if (row == N) {
		result++;
		return;
	}

	for (int col = 0; col < N; col++) {
		if (ischeck(col, row)) {
			chess[row] = col;
			back(row + 1);
			chess[row] = -1;
		}
	}
}

int main() {
	cin >> N;
	result = 0;
	back(0);
	cout << result << "\n";
}