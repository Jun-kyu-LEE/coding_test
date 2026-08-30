#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, M, K;
		//n명의 사람 m초의 시간 k개의 붕어빵 
		//입력으로 사람이 몇초에 도착하는지 올꺼야
		cin >> N >> M >> K;
		vector<int> arr;
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			arr.push_back(a);
		}
		sort(arr.begin(), arr.end());
		//i초에 만들수있는 붕어빵 
		//m초에 만들어지는 붕어방 
		int count = 0;
		int people = 0;
		int max_value = arr[N - 1];
		bool result = true;
		for (int i = 0; i <= max_value; i++) {
			
			if (i %M==0&&i!=0)count += K;
			while (i == arr[people]) {
				count--;
				people++;
				if (count < 0) { result = false; break;  }
			}
			if (people == N)break;
		}
		if (result) {
			cout << "#" << tc << " Possible\n";
		}
		else cout << "#" << tc << " Impossible\n";
	}
}