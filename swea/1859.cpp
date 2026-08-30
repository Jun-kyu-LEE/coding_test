#include<iostream>
#include<vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++){
	
		int N;
		cin >> N;
		vector<int>arr(N, 0);

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		int maxVal = -1;
		long long result = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (maxVal < arr[i]) { maxVal = arr[i]; }
			else {
				result += maxVal - arr[i];
			}
		}
		cout << "#" << tc << " " << result << "\n";
	}
}