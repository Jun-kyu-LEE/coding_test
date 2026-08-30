#include<queue>
#include<iostream>
using namespace std;

int dx[3] = { 0,0,-1 };
int dy[3] = { 1,-1,0 };

int main() {
	
	for (int tc = 1; tc <= 10; tc++) {
		int dummy;
		cin >> dummy;

		int board[100][100];
		bool vis[100][100];
		int st_x, st_y;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> board[i][j];
				vis[i][j] = false;

				if (board[i][j] == 2) {
					st_x = i; //행
					st_y = j; //열
				}

			}
		}
		queue<pair<int, int>>q;
		q.push({ st_x,st_y });
		vis[st_x][st_y] = 1;

		int result = 0;

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			if (cur.first == 0) {
				result = cur.second;
				break;
			}

			bool flag = false;
			for (int dir = 0; dir < 3; dir++) {
				if (!flag) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100)continue;
					if (board[nx][ny] != 1||vis[nx][ny])continue;
					vis[nx][ny] = 1;
					q.push({ nx,ny });
					flag = true;
				}
			}
		}
		cout << "#" << tc << " " << result << "\n";


	}
}