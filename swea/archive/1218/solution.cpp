#include<iostream>
#include<stack>
using namespace std;

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int N;
		cin >> N;
		string s;
		cin >> s;
	
		stack<int>st;
		//( 0 [ 1 {2 <3
		bool flag = true;
		for (int i = 0; i < N; i++) {
			char c = s[i];
			if (c == '(')st.push(0);
			else if (c == '[')st.push(1);
			else if (c == '{')st.push(2);
			else if (c == '<')st.push(3);
			else {
				int need;
				if (c == ')') need = 0;
				else if (c == ']') need = 1;
				else if (c == '}') need = 2;
				else need = 3;

				if (st.empty() || st.top() != need) { flag = false; break; }
				st.pop();
			}
		}
		if (!st.empty()) flag = false;

		if(!flag)cout << "#" << tc <<" "<< 0 << "\n";
		else cout << "#" << tc << " " << 1 << "\n";
	}
}