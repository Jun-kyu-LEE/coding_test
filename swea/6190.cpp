#include<iostream>
#include<vector>
using namespace std;

bool IsIncreas(int a) {
	int temp = a % 10;
	while (a != 0) {
		a = a / 10;
		int b = a % 10;
		if (b > temp)return false;
		temp = b;
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		vector<int>v(N);
		for (int i = 0; i < N; i++)cin >> v[i];

	    int result = -1;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int temp =v[i] * v[j];
				if (IsIncreas(temp)) {
					result = max(result, temp);
				}
			}
		}
		cout << "#" << tc << " " << result << "\n";
	}
}