#include<iostream>
using namespace std;
int N, K;
bool vis[10];
int arr[10][10];
int per[10];//K
//K가 target
//depth가 뭔지 -->일번호
//i가 뭔지-->사람번호

//vis가 먼지를 잘 생각해봐 -->vis[i]-->사람 i가 일을 맡았는지 아닌지

int result = 0;
void back(int depth,int sum) {
	if (sum >= result)return;

	if (depth == N) {
		result = min(result, sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (vis[i])continue;
		vis[i] = true;
		back(depth + 1, sum + arr[i][depth]);
		vis[i] = false;
	}


}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)cin >> arr[i][j];
	}
	result = 1e9;
	back(0, 0);
	cout << result << "\n";
}