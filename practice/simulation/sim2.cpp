#include<iostream>
#include<vector>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int board[10][10];
bool vis[10][10];

int main() {
	int N, M;
	cin >> N >> M;
	
	int st_x, st_y, dir;
	cin >> st_x >> st_y >> dir;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	int result = 1;
	vis[st_x][st_y] = 1;
	int x = st_x;
	int y = st_y;
	int count = 0;

	while (1) {
		vis[x][y] = 1;

		dir = (dir + 3) % 4;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		if (!vis[nx][ny]&&board[nx][ny]==0) {
			result++;
			x = nx;
			y = ny;
			count = 0;
		}
		else {
			count++;
			if (count == 4) {
				nx = x + dx[(dir + 2) % 4];
				ny = y + dy[(dir + 2) % 4];
				if (board[nx][ny] == 1)break;
				x = nx;
				y = ny;
				count = 0;
			}
		}

	}
	cout << result << "\n";
}