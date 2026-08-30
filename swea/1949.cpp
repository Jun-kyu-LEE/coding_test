#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int board[10][10];

struct road {
	int x;
	int y;
	int cur_h;
	bool flag;
	int count;
};

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, K;
		cin >> N >> K;

		vector<pair<int, int>>max_h;

		int temp = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
				if (board[i][j] > temp)temp = board[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == temp)max_h.push_back({ i,j });
			}
		}
		stack<road>st;
		int result = 0;
		for (int i = 0; i < max_h.size(); i++) {

			

			int st_x, st_y;
			st_x = max_h[i].first;
			st_y = max_h[i].second;	
			road r = { st_x,st_y,board[st_x][st_y],false,0 };
			st.push(r);
			
			while (!st.empty()) {
				auto cur = st.top();
				st.pop();
				int x = cur.x;
				int y = cur.y;
				int cur_heigth = cur.cur_h;
				bool flag = cur.flag;
				int count = cur.count;

				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
				
					
					if (flag) {
						if (board[nx][ny] >= cur_heigth)continue;
						st.push({ nx,ny,board[nx][ny],flag,count+1 });
						
					}
					else {
						if (board[nx][ny] >= cur_heigth) {
							int height_temp = 0;
							if (board[nx][ny] - cur_heigth >= K)continue;
							else { 
								height_temp = cur_heigth - 1;  
								st.push({ nx,ny,height_temp,true,count+1 });
								
							}
						}
						else {
							st.push({ nx,ny,board[nx][ny],flag,count+1 });
	
						}
					}
				}
				if (result < count)result = count;
			}


		}

		cout << "#" << tc << " " << result << "\n";

	}
}