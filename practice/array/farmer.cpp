#include<iostream>
#include<string>
#include<vector>
using namespace std;
int board [50][50];
int main() {
	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		int N;
		cin >> N;
		char num;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> num;
				int temp = num - '0';
				board[i][j] = temp;
			}
		}
		int st = N / 2;
		int sum = 0;
		for (int i = 0; i <st; i++) {
			sum += board[i][st];
			for (int j = 1; j <= i; j++) {
				sum += board[i][st-j];
				sum += board[i][st + j];
			}
		}
		for (int i = 0; i < N; i++) {
			sum += board[st][i];
		}
		int margin = st - 1;
		for (int i = st + 1; i < N; i++) {
			sum += board[i][st]; //4 3
			for (int j = 1; j <= margin; j++) {
				sum += board[i][st - j];  //4 1
				sum += board[i][st + j];
			}
			margin--;
		}
		cout << "#" << test_case << " " << sum<<"\n";



	}
}