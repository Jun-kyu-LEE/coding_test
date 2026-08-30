#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		cin >> N >> M;
		vector<vector<int>>group(N+1);
		vector<int>index(N, -1);
		int index = 0;
		for (int i = 0; i < M; i++) {
			int c, a, b;
			cin>> c>> a >> b;
			if (b > a) swap(a, b);
			if (c == 0) {
				group[a].push_back(b);
				group[b].push_back(a);
			
			}
		}
	}

}