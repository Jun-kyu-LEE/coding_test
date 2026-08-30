#include<iostream>
#include<string>
using namespace std;

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int T;
		cin >> T;
		string target, s;
		cin >> target;
		cin >> s;
		char st = target[0];
		int target_size = target.size();
		int result = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != st)continue;
			else {
				bool flag = true;
				for (int j = 1; j < target_size; j++) {
					if (s[i + j] != target[j]) { flag = false;  break;}
				}
				if (flag)result++;
			}
		}
		cout << "#" << tc << " " << result << "\n";
	}
}