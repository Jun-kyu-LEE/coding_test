#include <iostream>
#include <string>
using namespace std;

string code[10] = {
    "0001101","0011001","0010011","0111101","0100011",
    "0110001","0101111","0111011","0110111","0001011"
};

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, M;
        cin >> N >> M;

        string board[55];
        for (int i = 0; i < N; i++) cin >> board[i];

        // 1이 있는 줄 하나 찾고, 그 줄의 마지막 1 위치 구하기
        int row = -1, endPos = -1;
        for (int i = 0; i < N && row == -1; i++)
            for (int j = M - 1; j >= 0; j--)
                if (board[i][j] == '1') { row = i; endPos = j; break; }

        int digit[8];
        int start = endPos - 55;
        string s = "";          
        for (int i = 0; i < 56; i++) {
            s += board[row][start + i];
        }
        

        for (int j = 0; j < 8; j++) {
            string temp = "";
            for (int i = 0; i < 7; i++) {
                temp += s[j * 7 + i];
            }
            for (int d = 0; d < 10; d++) {
                if (temp == code[d]) { digit[j] = d; break;} 
            }
        }

        int odd = 0, even = 0;
        for (int k = 0; k < 8; k++) {
            if (k % 2 == 0) odd += digit[k];  // 1,3,5,7번째 = 인덱스 0,2,4,6
            else even += digit[k];
        }

        int sum = odd + even;
        cout << "#" << tc << " " << ((odd * 3 + even) % 10 == 0 ? sum : 0) << "\n";
    }
}