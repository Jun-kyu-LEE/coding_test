#include <iostream>
#include <string>
#include <numeric>

using namespace std;

string A;

void shift() {
    int size = A.size();
    char temp = A[size - 1];
    char carry = A[0];
    for (int i = 1; i < size; i++) {
        char t = carry;
        carry = A[i];
        A[i] = t;
    }
    A[0] = temp;
}

int check() {
    int size = A.size();
    string s = "";
    s+=A[0];
    int count = 1;
    for (int i = 1; i < size; i++) {
        if (A[i] != A[i - 1]) {
            s += to_string(count);
            s += A[i];
            count = 1;
        }
        if (A[i] == A[i - 1]) {
            count++;
        }
    }
    s += to_string(count);
    return s.size();
}

int main() {
    cin >> A;
    int answer = 1e9;
    for (int i = 0; i <= A.size(); i++) {
        shift();
        answer = min(answer, check());
    }
    cout << answer;
    // Please write your code here.

    return 0;
}
//오론쪽으로 순환 shift한다음에  길이 구하기
//압축하는거야
