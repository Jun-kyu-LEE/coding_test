#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int result = 0;
int N;
vector<pair<int, int>>people(N);
int h_x, h_y;
bool vis[11];

void dfs(int cnt,int sum,int x,int y) {

	if (sum >= result)return;

	if (cnt == N) {
		sum += abs(h_x - x) + abs(h_y - y);
		if (result > sum) {
			result = sum;
			return;
		}
	}

	for (int i = 0; i < N; i++) {
		if (vis[i] == 0) {
			auto cur = people[i];
			vis[i] = 1;
			dfs(cnt + 1, sum + abs(x - cur.first) + abs(y - cur.second), cur.first, cur.second);
			vis[i] = 0;
		}
	}
	return;
}

/*
DFS형식

void dfs(int cnt){
	if(cnt==목표){
	 //그때 연산
	}

	for(int i=0; i<N; i++){
	    if(vis[i]==0){ //아직 방문하지 않았으면
		  //연산
		  vis[i]=1 //방문표시
		  dfs(cnt+1) //증가시키기
		  vis[i]=0 //방문표시 제거 
		}
	}

}
이게 기본적인 순열 형식인건가?


*/






int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		people.clear();
		cin >> N;
		
		int s_x, s_y;
		cin >> s_x >> s_y >> h_x >> h_y;	
		
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			people.push_back({ x,y });
			vis[i] = 0;
		}
		result = 99999999;
		dfs(0, 0, s_x, s_y);
		cout << "#" << tc << " " << result << "\n";



	}
}