#include<iostream>
#include<vector>
#include<algorithm>
#include <deque>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = { 1,0 ,- 1,0 };
bool body[100][100];
int apple[100][100];

int main() {
	int N, K, L;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		apple[a][b] = 1;
	}
	vector<pair<int, char>>change_dir;
	cin >> L;
	for (int i = 0; i < L; i++) {
		int t;  char c;
		cin >> t >> c;
		change_dir.push_back({ t,c });
	}
	sort(change_dir.begin(), change_dir.end());
	int count = 0;
	int time = 0;
	int dir = 0;
	int x = 0,y=0;
	int size = 1;
	deque<pair<int, int>>snake;
	snake.push_front({ 0,0 }); 

	while (1) {
		time++;
		if (count<L&&change_dir[count].first == time) {
			if (change_dir[count].second == 'D')dir = (dir + 1) % 4;
			else dir = (dir+3) % 4;
			count++;
		}

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) { break; }
		if (body[nx][ny] == true) {  break; }
		body[nx][ny] = true;
		if (apple[nx][ny]) {
			apple[nx][ny] = 0;
		}
		else {
			auto cur = snake.back();
			int temp_x = cur.first;
			int temp_y = cur.second;
			snake.pop_back();
			body[temp_x][temp_y] = false;
		}
		snake.push_front({ nx,ny });
		x = nx;
		y = ny;
	}
	cout << time << "\n";
}