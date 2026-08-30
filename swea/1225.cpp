#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	
	for (int tc = 1; tc <= 10; tc++) {
		int arr[8] = { 0, };
		int dummy;
		cin >> dummy;
		int result[8] = { 0, };
		for (int i = 0; i < 8; i++) {
			cin >> arr[i];
		}
		int count = 1;
		int index = 0;
		//특정값이 0이되면 그 index가 7이 되도록 바꿔야하고 index+1이 0이 되도록 바꾸면 되는거야 
		while (1) {
			arr[index] = arr[index] - count;
			if (arr[index] <= 0) { arr[index] = 0; break; }
			count++;
			index++;
			if (count == 6)count = 1;
			if (index == 8)index = 0;
		}
		
		cout << "#" << tc << " ";
		//0인거 만나면 그이후로 계속 push하고 아니면 빼기 
		for (int i = 0; i < 8; i++) {
			result[i] = arr[(index + 1 + i) % 8];
		}

		for (int i = 0; i < 8; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}
}