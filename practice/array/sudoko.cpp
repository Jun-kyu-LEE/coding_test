#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int board[10][10];
	bool a[10];
	bool b[10];
	
	for (int test_case = 1; test_case <= T; test_case++) {
		int flag = 1;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> board[i][j];
			
			}
		}

		for (int i = 1; i <=9; i++) {
			for (int k = 1; k <= 9; k++) a[k] = false;
			
			for (int j = 0; j < 9; j++) {
				int temp = board[i-1][j];
				a[temp] = true;
			
			}
			for (int k = 1; k <= 9; k++) {
				if (!a[k]) { // 1~9 중 하나라도 false라면?
					flag = 0; // 이 스도쿠는 잘못됨
					break;
				}
			}
		}

		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) a[k] = false;

			for (int i = 0; i < 9; i++) {
				int temp = board[i][j-1];
				b[temp] = true;

			}
			for (int k = 1; k <= 9; k++) {
				if (!a[k]) { // 1~9 중 하나라도 false라면?
					flag = 0; // 이 스도쿠는 잘못됨
					break;
				}
		}
        
	

		
		cout << "#" << test_case << " " << flag<<"\n";
	}
}