#include<iostream>
#include<vector>
using namespace std;
int main() {
    for (int tc = 1; tc <= 10; tc++) {
        //회문의 길이가 안정해져있어
        int dummy;
        cin >> dummy;
        string board[100];
        for (int i = 0; i < 100; i++) {
            cin >> board[i];
        }
        int result = 1;

        int size = -1;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                int left = 1;
                int right = 1;
                if (i >= 1 && board[i - 1][j] == board[i][j]) {
                    left++;
                }
                while (i - left >= 0 && i + right < 100) {
                    if (board[i - left][j] == board[i + right][j]) {
                        left++;
                        right++;
                    }
                    else {

                        break;
                    }
                }
                size = left + right + 1;
                result = max(size, result);
                ////////////////////////위아래로
                left = 1;
                right = 1;
                if (j >= 1 && board[i][j - 1] == board[i][j]) {
                    left++;
                }
                while (j - left >= 0 && j + right < 100) {
                    if (board[i][j - left] == board[i][j + right]) {
                        left++;
                        right++;
                    }
                    else {
                        break;
                    }
                }
                size = left + right + 1;
                result = max(size, result);

            }
        }
        cout << "#" << dummy << " " << result << "\n";
    }
}