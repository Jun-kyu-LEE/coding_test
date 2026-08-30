#include<iostream>
using namespace std;
int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int board[10][10];
bool vis[10][10];
int result = 0;

bool isAdj(int x, int y) {
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
		if (vis[nx][ny] == true)return true;
	}
	return false;
}

void back(int st, int sum, int depth) {
	if (N * N - st < M - depth) return;
	if (depth == M) {
		result = max(result, sum);
		return;
	}
	for (int i = st; i < N * N; i++) {
		int x = i / N;
		int y = i % N;
		if (isAdj(x, y))continue;
		vis[x][y] = true;
		back(i + 1, sum + board[x][y], depth + 1);
		vis[x][y] = false;
	}
	
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)cin >> board[i][j];
	}
	back(0, 0, 0);
	cout << result << "\n";
}