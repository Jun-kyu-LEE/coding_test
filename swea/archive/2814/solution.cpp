#include<iostream>
#include<vector>
using namespace std;

bool map[11][11];
bool vis[11];
int N, M;
int result = 0;

void dfs(int current, int count) {
	// 1. 방에 들어오자마자 최고 기록 갱신! (종료 조건이랄 게 딱히 없습니다)
	if (count > result) {
		result = count;
	}

	// 2. 다음 갈 곳 찾기
	for (int next = 1; next <= N; next++) {
		// 연결되어 있고 안 가본 곳이면 쏙 들어감
		if (map[current][next] == 1 && vis[next] == 0) {
			vis[next] = 1;
			dfs(next, count + 1); // 길이(count) 1 증가시켜서 다음 방으로!
			vis[next] = 0;
		}
	}
	// 갈 곳 없으면 알아서 for문 끝나고 돌아감~ 꿀!
}


int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		cin >> N >> M;
		
		for (int i = 0; i <= N; i++) {
			map[i][i] = 0;
			vis[i] = 0;
		}
		

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
			map[b][a] = 1;
		}
		result = 0;
	
		for (int i = 1; i <= N; i++) {
			
			 vis[i] = 1;
			 dfs(i, 1);
			 vis[i] = 0;
		}
		cout << "#" << tc << " " << result<< "\n";
	}
}