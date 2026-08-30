#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		string s;
		cin >> s;
		int size = s.size();
		int flag = 0;
		int result = 0;
		for (int i = 0; i < size; i++) {
			if (s[i]-'0' == flag)continue;
			else {
				result++;
				flag = s[i] - '0';
			}
		}
		cout << "#" << tc << " " << result << "\n";
	}
}