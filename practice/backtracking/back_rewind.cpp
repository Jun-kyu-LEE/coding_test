#include<iostream>
#include <queue>
using namespace std;

int N, K;
int arr[10];
int com[10];
int per[10];
int result;
bool vis[10];

void back(int depth, int st) {
	if (depth == K) {
		for (int i = 0; i < K; i++)cout << com[i]<<" ";
		cout << "\n";
		return;
	}

	for (int i = st; i < N; i++) {
		com[depth] = i+1;
		back(depth+1, i+ 1);
	}
}

void back2(int sum,int size,int st) {
	if (sum > K)return;
	if (sum == K) {
		for(int i=0; i<size; i++)cout<<com[i]<<" ";
		return;
	}
	for (int i = st; i < N; i++) {
		back2(sum + arr[i], size + 1,i);
	}
}

void back3(int depth) {
	if (depth == N) {
		int sum = 0;
		for (int i = 1; i < N; i++)sum += abs(per[i] - per[i - 1]);
		result = max(result, sum);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (vis[i])continue;
		vis[i] = true;
		per[depth] = arr[i];
		back3(depth + 1);
		vis[i] = false;
	}
}
int M;
void back4(int depth,int sum, int st) {
	if (sum > M)return;
	if (depth == K) {
		result++;
		return;
	}
	for (int i = st; i < N; i++) {
		back4(depth + 1, sum + arr[i], i + 1);
	}
}
int total; //능력치 전체합
void back5(int depth, int st,int sum) {
	if (depth == N / 2) {
		result = min(result, abs(total - 2 * sum));
		return;
	}
	for (int i = st; i < N; i++) {
		back5(depth + 1, i + 1, sum + arr[i]);
	}
}

int board[10];
bool check(int col, int row) {
	
	for (int i = 0; i < row; i++) {
		if (board[i] == col)return false;
		if (abs(board[i] - col) == abs(i - row))return false;
	}
	return true;
}

void back6(int row) {
	if (row == N) {
		result++;
		return;
	}
	for (int col = 0; col < N; col++) {
		if (check(col, row)) {
			board[row] = col;
			back6(row + 1);
		}
	}
}
int op[4];
int r_max;
int r_min;
void back7(int depth,int sum) {
	if (depth == N-1) {
		r_max = max(r_max, sum);
		r_min = min(r_min, sum);
		return;
	}
	for (int i = 0; i <4; i++) {
		if (op[i] == 0)continue;
		op[i]--;
		if (i == 0)back7(depth + 1, sum + arr[depth + 1]);
		if (i == 1)back7(depth + 1, sum - arr[depth + 1]);
		if (i == 2)back7(depth + 1, sum * arr[depth + 1]);
		if (i == 3)back7(depth + 1, sum / arr[depth + 1]);
		op[i]++;
	}
}
int S;
void back8(int sum,int st) {
	if (sum > S)return;
	if (sum == S) {
		result++;
		return;
	}
	for (int i = st; i < N; i++) {
		back8(sum + arr[i], i + 1);
	}
}
int board[10][10];
bool vis2[10][10];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool isadj(int x, int y) {
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
		if (vis2[nx][ny] == true)return true;
	}
	return false;
}
int board2[10][10];
void back9(int depth,int sum,int st) {
	
	if (depth == M) {
		result = max(result, sum);
		return;
	}
	for (int i = st; i < N * N; i++) {
		int x = i / N; int y = i % N;
		if (isadj(x, y))continue;
		vis2[x][y] = 1;
		back9(depth+1,sum+board2[x][y],i+1);
		vis2[x][y] = 0;
	}
}

void back10(int depth,int st) {
	if (depth == M) {
		int temp[10][10];
		queue<pair<int, int>>q;
		for(int i=0; i<N; i++)
			for (int j = 0; j < N; j++) {
				vis2[i][j] = 0;
				temp[i][j] = board2[i][j];
				if (temp[i][j] == 1) {
					q.push({ i,j });
					vis2[i][j] = true;
				}
			}
		//BFS코드
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
				if (temp[nx][ny] != 0)continue;
				if (vis2[nx][ny] == true)continue;
				vis2[nx][ny] = true;
				temp[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
		int count = 0;
		for(int i=0; i<N; i++)
			for (int j = 0; j < N; j++) {
				if (temp[i][j] == 0)count++;
			}
		result = max(result, count);
		return;
	}

	for (int i = st; i < N * N; i++) {
		int x = i / N; int y = i % N;
		if (board2[x][y] != 0)continue;
		board2[x][y] = 2;
		back10(depth + 1, i + 1);
		board2[x][y] = 0;
	}


}