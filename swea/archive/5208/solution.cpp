#include<iostream>
#include<vector>
using namespace std;

int N;
int result = 9999999;
bool vis[101];
vector<int>bus(N - 1);


void dfs(int idx, int cnt) {
	if (cnt >= result)return;

	if (idx >= N) {
		if(result>cnt)result=cnt;
		return;
	}
	dfs(idx + 1, cnt + 1, bus[idx] - 1);

	// 선택 B: 이번엔 안 갈고 그냥 통과한다!
	// (에너지가 0보다 클 때만 가능함)
	if (energy > 0) {
		dfs(idx + 1, cnt, energy - 1);
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		bus.clear();
		cin >> N;
		
		for (int i = 0; i < N - 1; i++) {
			cin >> bus[i];
			vis[i] = 0;
		}
		int baterry = bus[0];
		dfs(1, baterry, 0);
		cout << "#" << tc << " " << result << "\n";
	}
}