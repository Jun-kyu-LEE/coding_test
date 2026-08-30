#include<iostream>
#include<queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		priority_queue<pair<int, int>>pq;
		int V, E;
		cin >> V >> E;
		vector < vector<pair<int, int>>>adj(V + 1);

		int A, B, C;
		for (int i = 0; i < E; i++) {
			cin >> A >> B >> C;
			adj[A].push_back({ B,C });
			adj[B].push_back({ A,C });
		}

		vector<bool>visited(V + 1, false);

		

		long long totalWeight = 0;
		int visitedCount = 0;

		pq.push({ 0,1 });

		while (!pq.empty() && visitedCount < V) {
			auto cur = pq.top();
			int w = -cur.first;
			int node = cur.second;
			pq.pop();

			if (visited[node])continue;

			visited[node] = true;
			visitedCount++;
			totalWeight += w;

			for (auto next : adj[node]) {
				int nxt = next.first;
				int weight = next.second;
				if (!visited[nxt]) {
					pq.push({ -weight,nxt });
				}
			}
		}

		cout << "#" << tc << " " << totalWeight << "\n";
	}
}