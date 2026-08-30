#include<iostream>
using namespace std;


bool Checked(string a) {
	int left = 0;
	int right = a.size() - 1;
	while (left < right) {
		if (a[left] != a[right])return false;
		left++;
		right--;
	}
	return true;
}

int main() {
	
	for (int tc = 1; tc <= 10; tc++) {
		int N;
		cin >> N;
		//N은 회문의 길이야 4개만 찾아보면 되는거지

		string board[8];
		for (int i = 0; i < 8; i++) {
			cin >> board[i];
		}
		int result = 0;
		
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				string temp1 = "";
				string temp2 = "";
				bool flag1 = true;
				bool flag2 = true;
				for (int k = 0; k < N; k++) {
					if (j + N <= 8) { temp1 += board[i][j + k]; }
					else flag1 = false;
					
					if (i + N <= 8)	temp2 += board[i + k][j];
					else flag2 = false;
				}
				if (Checked(temp1)&&flag1)result++;
				if (Checked(temp2)&&flag2)result++;
			}
		}
		cout << "#" << tc << " " << result << "\n";
	}
}