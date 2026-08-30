#include<iostream>
using namespace std;


int N, M;
int arr[10];
bool visited[10];

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[depth] = i;
			dfs(depth + 1);
			visited[i] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	dfs(0);
}