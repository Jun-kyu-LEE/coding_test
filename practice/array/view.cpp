#include<iostream>
#include<vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		vector<int>building(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> building[i];
		}
		long long result = 0;
		for (int i = 2; i < N - 2; i++) {
			int max1 = -1;
			int max2 = -1;
			for (int j = 1; j <= 2; j++) {
				max1 = max(max1, building[i - j]);
				max2 = max(max2, building[i + j]);
			}
			max2 = max(max1, max2);
			if (max2 < building[i])result += (building[i] - max2);
		}
		cout << "#" << tc << " " << result << "\n";

	}
}