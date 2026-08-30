#include<iostream>
#include<unordered_set>
#include<queue>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	char board[4][4];
	for (int tc = 1; tc <= T; tc++) {
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> board[i][j];
			}
		}
		
		unordered_set<string>set;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				queue<pair<pair<int, int>, string>>q;
				string temp = "";
				temp += board[i][j];
				q.push({ {i,j},temp });

				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					if (cur.second.size() == 7) {
						set.insert(cur.second);
						continue;
					}
					for (int dir = 0; dir < 4; dir++) {
						int x = cur.first.first;
						int y = cur.first.second;
						int nx = x + dx[dir];
						int ny = y + dy[dir];
						if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)continue;
						q.push({ {nx,ny},cur.second + board[nx][ny] });
					}
				}

			}

		}
		cout << "#" << tc << " " << set.size() << "\n";

	}
}