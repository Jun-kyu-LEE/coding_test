#include <iostream>

using namespace std;

string expression;

int val[6];
//a b c d e f에 숫자 1~4까지 다 넣어보기
int ans;
void go(int idx) {
    if (idx == 6) {
        //계산하기
        int result = 0;
        int size = expression.size();
        int temp;
        char op = '+';
        for (int i = 0; i < size; i++) { // 0번부터
            if (expression[i] == '-') op = '-';
            else if (expression[i] == '+') op = '+';
            else if (expression[i] == '*') op = '*';
            else {
                int temp = val[expression[i] - 'a'];
                if (op == '-') result -= temp;
                else if (op == '+') result += temp;
                else if (op == '*') result *= temp;
            }
        }
        ans = max(ans, result);
        return;
    }

    for (int num = 1; num <= 4; num++) {
        val[idx] = num;
        go(idx + 1);
    }
}

int main() {
    cin >> expression;

    // Please write your code here.
    ans = -1e9;
    go(0);
    cout << ans;
    return 0;
}
