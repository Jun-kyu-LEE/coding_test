#include<iostream>
using namespace std;

int arr[10];
int op[4];
int result_max = 0;
int result_min = 0;
int N,K;
bool vis[10];

void back(int depth,int sum) {
	if (depth == N-1) {
		result_max = max(result_max, sum);
		result_min = min(result_min, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] == 0)continue;
		op[i]--;
		if (i == 0) back(depth + 1, sum + arr[depth + 1]);  // ? sum 직접 안 건드리기
		if (i == 1) back(depth + 1, sum - arr[depth + 1]);
		if (i == 2) back(depth + 1, sum * arr[depth + 1]);
		if (i == 3) back(depth + 1, sum / arr[depth + 1]);
		op[i]++;
	}

}

int main() {
	cin >> N>>K;
	for (int i = 0; i < N; i++) { cin >> arr[i]; vis[i] = 0; }
	result_max = 0;
	result_min = 0;
	back(0, arr[0]);
	cout << result_max << " " << result_min << "\n";
}