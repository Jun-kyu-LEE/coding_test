#include<iostream>
using namespace std;

int arr[21];
bool vis[21];
int result;
int N, K;

void dfs(int idx, int sum) {
	// 1. 종료 조건: N개의 숫자를 모두 확인했을 때
	if (idx == N) {
		if (sum == K) {
			result++; // 합이 K와 같다면 정답 카운트 1 증가
		}
		return; // 더 이상 탐색할 숫자가 없으므로 돌아감
	}

	// 2. 현재 숫자(arr[idx])를 선택하는 경우
	// 다음 숫자(idx + 1)로 넘어가고, 합(sum)에 현재 숫자를 더해줍니다.
	dfs(idx + 1, sum + arr[idx]);

	// 3. 현재 숫자(arr[idx])를 선택하지 않는 경우 (백트래킹)
	// 다음 숫자(idx + 1)로 넘어가되, 합(sum)은 그대로 둡니다.
	dfs(idx + 1, sum);
}


int main() {
	int T;
	cin >> T;
	for (int tc=1; tc <= T; tc++) {
		
		cin >> N >> K;
		//N개의 숫자중 합이 K가 되도록 하는 경우 의수

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		result = 0;
		dfs(0,0);
		cout << "#" << tc << " " << result << "\n";

	}
}