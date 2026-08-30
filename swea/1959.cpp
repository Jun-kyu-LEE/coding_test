#include<iostream>
using namespace std;

//n과 m은 3이상 20이하

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int arr1[21];
		int arr2[21];
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> arr1[i];
		}

		for (int i = 0; i < M; i++) {
			cin >> arr2[i];
		}
		int result = 0;
		if (N == M) {
			for (int i = 0; i < N; i++) {
				result += arr1[i] * arr2[i];
			}
		}
		else if (N > M) {
			int size = N - M;
			for (int i = 0; i <= size; i++) {
				int sum = 0;
				for (int j = 0; j < M; j++) {
					sum += arr1[i + j] * arr2[j];
				}
				result = max(result, sum);
			}
		}
		else {
			int size = M-N;
			for (int i = 0; i <= size; i++) {
				int sum = 0;
				for (int j = 0; j < N; j++) {
					sum += arr1[j] * arr2[i+j];
				}
				result = max(result, sum);
			}
		}
		cout << "#" << tc << " " << result << "\n";

	}
}