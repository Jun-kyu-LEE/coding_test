#include<iostream>
#include<vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N;

		vector<int> score(N);
		vector<bool>visited(10001);
		int max_score = 0;
		for (int i = 0; i < N; i++) {
			cin >> score[i];
			max_score += score[i];
		}
		visited[0] = true;
		vector<int> pos_sc;
		pos_sc.push_back(0);

		for (int i = 0; i < N; i++) {
			int cur = score[i];
			int size = pos_sc.size();
			
			for (int j = 0; j < size; j++) {
				int new_num = pos_sc[j] + cur;
				if (visited[new_num])continue;
				visited[new_num] = 1;
				pos_sc.push_back(new_num);
			}

		}
		cout << "#" << test_case << " " << pos_sc.size() << "\n";

	}
}