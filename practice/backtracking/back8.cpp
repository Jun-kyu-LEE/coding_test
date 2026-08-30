#include<iostream>
#include<queue>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N, M;
int result = 0;

int board[10][10];
int temp[10][10];
bool vis[10][10];

void back(int depth,int st) {
	if (depth == M) {
		memset(vis, 0, sizeof(vis));
		int temp[10][10];
		queue<pair<int, int>> q;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				temp[i][j] = board[i][j];
				if (temp[i][j] == 1) {
					q.push({ i,j });
					vis[i][j] = true;
				}
			}
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
				if (vis[nx][ny]==true||temp[nx][ny] == 2)continue;
				vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}

		int count = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (temp[i][j] == 0) count++;
		result = max(result, count);
		return;
	}

	for (int i = st; i < N * N; i++) {
		int x = i / N; int y = i % N;
		if (board[x][y] != 0)continue;
		board[x][y] = 2;
		back(depth + 1, i + 1);
		board[x][y] = 0;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) { 
			cin >> board[i][j]; 
		}
	}
	result = -1;
	back(0, 0);
	cout << result << "\n";


}