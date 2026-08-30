#include<iostream>
using namespace std;

bool checked(string s) {
	int left = 0;
	int right = s.size() - 1;
	
	while (left <= right) {
		if (s[left] != s[right])return false;
		left++;
		right--;
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		string a;
		cin >> a;
		int result = 0;
		if (checked(a))result = 1;
		cout << "#" << tc << " " << result << "\n";
	}
}