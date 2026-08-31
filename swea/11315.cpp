
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
     
        int N;
        cin >> N;
        string s[21];
        for (int i = 0; i < N; i++) {
            cin >> s[i];
        }
   
        int count = 0;
        bool flag = false;
      
        for (int i = 0; i < N; i++) {
            if (flag)break;
            count = 0;
            for (int j = 0; j < N; j++) {
                if (s[i][j] == 'o')count++;
                else count = 0;
                if (count == 5) {
                    flag = true;
                    break;
                }
            }
        }
        count = 0;
     
        for (int i = 0; i < N; i++) {
            if (flag)break;
            count = 0;
            for (int j = 0; j < N; j++) {
                if (s[j][i] == 'o')count++;
                else count == 0;
                if (count == 5) {
                    flag = true;
                    break;
                }
            }
        }
        count = 0;
      //대각선
        int dy[2] = { 1, -1 }; 
        int dx[2] = { 1,  1 };

        for (int i = 0; i < N && !flag; i++) {
            for (int j = 0; j < N && !flag; j++) {
                if (s[i][j] != 'o') continue;  

                for (int d = 0; d < 2; d++) {
                    int cnt = 0;
                    int ny = i, nx = j;

                    // 범위 안이고 'o'인 동안 계속 전진
                    while (ny >= 0 && ny < N && nx >= 0 && nx < N && s[ny][nx] == 'o') {
                        cnt++;
                        ny += dy[d];
                        nx += dx[d];
                    }

                    if (cnt >= 5) { flag = true; break; }
                }
            }
        }


        if (flag) {
            cout << "#" << tc << " YES\n";
        }
        else cout << "#" << tc << " NO\n";
    }
    
}
