#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N,M;
		cin >> N>>M;
		vector<vector<int>>v(N + 1);
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b); //a<b //a보다 키큰사람들 넣는거ㅑㅇ.
		}
		queue<int>q;

		bool vis[505][505] = { false, };  //vis[a][b] a,b값이 들어가있는지 
		int result = 0;
		for (int i = 1; i <= N; i++) {
			q.push(i);
			vis[i][i] = true;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();

				for (int j = 0; j < v[cur].size(); j++) {
					int temp = v[cur][j];
					if (!vis[i][temp]) {
						q.push(temp);
						vis[i][temp] = true;
					}
				}
			}
		}
		
		for (int i = 1; i <= N; i++) {
			int temp = 0;
			for (int j = 1; j <= N; j++) {
				if (vis[i][j])temp++;
			}
			if (temp == N - 1 || temp == 1)result++;
		}
		cout << "#" << tc << " " << result << "\n";
	}

}