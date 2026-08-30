#include<iostream>
#include<cmath>
using namespace std;

int N;
int arr[20];
int temp = 0;
int result;

void dfs(int depth, int sum,int st) {
	if (depth == N / 2) {
		result = min(result, abs(temp - 2*sum));
		return;
	}
	for (int i = st; i < N; i++) {
		dfs(depth + 1, sum + arr[i], i);
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		temp += arr[i];
	}
	result = 1e9;
	dfs(0, 0, 0);
	cout << result << "\n";
}