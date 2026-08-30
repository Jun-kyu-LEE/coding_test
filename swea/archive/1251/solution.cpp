#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		vector<long long>dist(N,LLONG_MAX);
		vector<bool>vis(N, false);
		vector<pair<int, int>>v(N);
		int rate;
		for (int i = 0; i < N; i++) {
			cin >> v[i].first;
		}
		for (int i = 0; i < N; i++) {
			cin >> v[i].second;
		}
		cin >> rate;

		dist[0] = 0;

		long long total = 0;
		long long best = LLONG_MAX;

		for (int i = 0; i < N; i++) {
			int cur;
			
			for (int j = 0; j < N; j++) {
				if (vis[j])continue;
				if (dist[j] < best) {
					best = dist[j];
					cur = j;
				}
			}
			vis[cur] = true;
			total += dist[cur];

			for (int j = 0; j < N; j++) {
				if (vis[j])continue;
				long long dx = v[cur].first - v[i].first;
				long long dy = v[cur].second - v[i].second;
				long long d = dx * dx + dy * dy;
				if (d < dist[i])dist[i] = d;
			}
		}
		
		cout << "#" << tc << " " << (int)((total * rate)+0.5);
	}
}