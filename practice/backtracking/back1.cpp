#include<iostream>
using namespace std;
int arr[10];
bool vis[10];
int result;
int per[10];
int N;

void back(int depth) {
	if (depth == N) {
		int sum = 0;
		for (int i = 1; i < N; i++) {
			sum += abs(per[i] - per[i - 1]);
		}
		result = max(result, sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (vis[i])continue;
		vis[i] = true;
		per[depth] = arr[i];
		back(depth + 1);
		vis[i] = false;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	result = 0;
	back(0);
	cout << result << "\n";

}