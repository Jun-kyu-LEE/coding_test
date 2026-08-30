#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int T = 10;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N;
		vector<int>v(100);
		for (int i = 0; i < 100; i++) {
			cin >> v[i];
		}
		while (N--) {
			sort(v.begin(), v.end());
			if (v[0] == v[99])break;
			v[0]++;
			v[99]--;
			
		}
		sort(v.begin(), v.end());
		cout << "#" << test_case << " " << v[99] - v[0]<<"\n";



	}
}