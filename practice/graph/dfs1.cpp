#include<iostream>
#include<vector>
using namespace std;

//결국 노드에 연결되어있는 모든 간선을 타고 간다 그게 핵심인거거잖아.
//그래서 다음에 그값을 넘긴다

bool vis[10];
vector<int>g[10];
int result=0;
void dfs(int node) {

	vis[node] = true;
	

	for (int next : g[node]) {
		if (vis[next])continue;
		dfs(next);
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	result = 0;
	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			dfs(i);
			result++;
		}
	}
	cout << result << "\n";
}