#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, K;
        cin >> N >> K;
        //35 40 20
        int a, b, c;
        vector<pair<double, int>>v;
        for (int i = 1; i <= N; i++) {
            cin>>a >> b >> c;
            double temp = a * 0.35 + b * 0.40 + c * 0.2;
            v.push_back({ -temp,i });
        }
        sort(v.begin(), v.end());
        int RANK = N / 10;
        int Num = 0;
        for (int i = 0; i < N; i++) {
            if (v[i].second == K) {
                Num = i; break;
            }
        }
        
        int result = (Num) / RANK;
        cout << "#" << tc << " ";
        switch (result) {
        case 0: cout << "A+\n"; break;
        case 1: cout << "A0\n"; break;
        case 2: cout << "A-\n"; break;
        case 3: cout << "B+\n"; break;
        case 4: cout << "B0\n"; break;
        case 5: cout << "B-\n"; break;
        case 6: cout << "C+\n"; break;
        case 7: cout << "C0\n"; break;
        case 8: cout << "C-\n"; break;
        case 9: cout << "D0\n"; break;
        }
       
    }
}