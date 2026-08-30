#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector <pair<int, int>>g[100001];
bool vis[100001];

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int V, E;
		cin >> V >> E;
		for (int i = 1; i <= V; i++) {
			g[i].clear();
			vis[i] = false;
		}

		int a, b, w;
		for (int i = 0; i < E; i++) {
			cin >> a >> b >> w;
			g[a].push_back({ b,w });
			g[b].push_back({ a,w });
		}
		priority_queue<pair<int, int>>pq;
		long long result = 0;
	

		pq.push({ 0,1 });

		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();
			int weight = -cur.first;
			int node = cur.second;
			if (vis[node])continue;
			vis[node] = true;
			result += weight;

			for (auto next : g[node]) {
				int N = next.first;
				int w = next.second;
				if (vis[N])continue;
				pq.push({ -w,N });
			}
		}
		cout << "#" << tc << " " << result << "\n";
		

	}
}