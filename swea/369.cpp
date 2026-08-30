#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int count = 0;
		int temp = i;
		while (temp != 0) {
			if (temp % 10 == 3 || temp % 10 == 6 || temp % 10 == 9)count++;
			temp /= 10; 
		}
		if (count == 0)cout << i;
		else {
			for (int j = 0; j < count; j++)cout << "-";
		}
		cout << " ";
	}
}