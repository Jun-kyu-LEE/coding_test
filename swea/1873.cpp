#include<iostream>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

char board[21][21];

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int H, W;
		cin >> H >> W;
		int x=0, y=0,dir=0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> board[i][j];
				if (board[i][j] == '<') {
					x = i;
					y = j;
					dir = 3;
				}
				if (board[i][j] == '^') {
					x = i;
					y = j;
					dir = 1;
				}
				if (board[i][j] == '>') {
					x = i;
					y = j;
					dir = 2;
				}
				if (board[i][j] == 'v') {
					x = i;
					y = j;
					dir = 0;
				}
				
			}
		}
		//- 물, # 강철,* 벽돌, . 평지
		//맵밖이면 이동 x,
		//포탄은 벽돌은 파괴되어 평지-->벽이나 게임 맵밖으로 나갈때까지
		int N;
		cin >> N;//cmd의 size
		string cmd;
		cin >> cmd;

		for (int i = 0; i < N; i++) {
			if (cmd[i] == 'U') {
				dir = 1;
				board[x][y] = '^';

				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= H||ny<0||ny>=W)continue;
				if (board[nx][ny] == '-' || board[nx][ny] == '#' || board[nx][ny] == '*')continue;
				board[x][y] = '.';
				x = nx; y = ny;
				board[x][y] = '^';
			}
			if (cmd[i] == 'D') {
				dir = 0;
				board[x][y] = 'v';

				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
				if (board[nx][ny] == '-' || board[nx][ny] == '#' || board[nx][ny] == '*')continue;
				board[x][y] = '.';
				x = nx; y = ny;
				board[x][y] = 'v';
			}
			if (cmd[i] == 'L') {
				dir = 3;
				board[x][y] = '<';

				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
				if (board[nx][ny] == '-' || board[nx][ny] == '#' || board[nx][ny] == '*')continue;
				board[x][y] = '.';
				x = nx; y = ny;
				board[x][y] = '<';
			}
			if (cmd[i] == 'R') {
				dir = 2;
				board[x][y] = '>';

				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
				if (board[nx][ny] == '-' || board[nx][ny] == '#' || board[nx][ny] == '*')continue;
				board[x][y] = '.';
				x = nx; y = ny;
				board[x][y] = '>';
			}
			if (cmd[i] == 'S') {
				//D U R L
				if (dir == 0) {
					for (int i = x+1; i < H; i++) {
						if (board[i][y] == '*') { board[i][y] = '.'; break; }
						if (board[i][y] == '#')break;
					}
				}
				if (dir == 1) {
					for (int i = x-1; i >= 0; i--) {
						if (board[i][y] == '*') { board[i][y] = '.'; break; }
						if (board[i][y] == '#')break;
					}
				}
				if (dir == 2) {
					for (int i = y+1; i < W; i++) {
						if (board[x][i] == '*') { board[x][i] = '.'; break; }
						if (board[x][i] == '#')break;
					}
				}
				if (dir == 3) {
					for (int i = y-1; i >= 0; i--) {
						if (board[x][i] == '*') { board[x][i] = '.'; break; }
						if (board[x][i] == '#')break;
					}
				}

			}//if문끝

		}//for문 끝
		cout << "#" << tc<<" ";
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (i == x && j == y) {
					if (dir == 0)board[i][j] = 'v';
					if (dir == 1)board[i][j] = '^';
					if (dir == 2)board[i][j] = '>';
					if (dir == 3)board[i][j] = '<';
				}
				cout << board[i][j];
			}
			cout << "\n";
		}
		
	}
	
}