#include<iostream>
using namespace std;
int N, K,M;
int arr[15];
int result, sum;

void back(int depth, int sum,int st) {
	if (sum > M)return;
	if (depth == K) {
		if (sum <= M)result++;
		return;
	}

	for (int i = st; i < N; i++) {

		back(depth + 1, sum + arr[i], i + 1);

	}

}

int main() {
	cin >> N >> K>>M;
	for (int i = 0; i < N; i++)cin >> arr[i];
	result = 0;
	back(0, 0, 0);
	cout << result << "\n";
}