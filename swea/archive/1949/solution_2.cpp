#include<iostream>
#include<cstring>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int board[10][10];
bool vis[10][10];
int result = 0;
int N, K;
void dfs(int x, int y, bool used, int count) {
	result = max(result, count);

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
		if (vis[nx][ny]==1)continue;

		if (board[nx][ny] < board[x][y]) {
			vis[nx][ny] = 1;
			dfs(nx,ny, used, count + 1);
			vis[nx][ny] = 0;
		}

		else if (!used && board[nx][ny] - K < board[x][y]) {
			int original = board[nx][ny];
			board[nx][ny] = board[x][y] - 1;
			vis[nx][ny] = 1;
			dfs(nx, ny, true, count + 1);
			vis[nx][ny] = 0;
			board[nx][ny] = original;
		}

	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
	
		cin >> N >> K;
		int temp = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j]; 
				if (temp < board[i][j])temp = board[i][j];
			}
		}
	  result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == temp) {
					memset(vis, false, sizeof(vis));
					vis[i][j] = 1;
					dfs(i, j,false, 1);
				}
			}
		}
		cout << "#" << tc << " " << result << "\n";

	}
}