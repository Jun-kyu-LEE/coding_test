#include<iostream>
#include<queue>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int T;
		cin >> T;
		char board[16][16];
		bool vis[16][16];
		int st_col, st_row,dt_col,dt_row;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				cin >> board[i][j];
				vis[i][j] = 0;
				if (board[i][j] == '2') { st_col = i; st_row = j; }
				if (board[i][j] == '3') { dt_col = i; dt_row = j; }
			}
		}
		queue<pair<int, int>>q;
		q.push({ st_col,st_row });
		vis[st_col][st_row] = 1;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			if (cur.first == dt_col && cur.second == dt_row)break;
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16)continue;
				if (board[nx][ny] == '1')continue;
				if (vis[nx][ny] == 1)continue;
				q.push({ nx,ny });
				vis[nx][ny] = 1;
			}
		}
		int result=0;
		if (vis[dt_col][dt_row])result = 1;

		cout << "#" << tc << " " << result << "\n";
	}
}