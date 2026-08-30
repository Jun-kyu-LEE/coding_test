#include<iostream>
using namespace std;
int N, S;
int result = 0;
int arr[10];
void back(int sum,int st) {
	if (sum > S)return;
	if (sum == S) {
		result++;
		return;
	}
	for (int i = st; i < N; i++) {
		back(sum + arr[i], i + 1);
	}
}