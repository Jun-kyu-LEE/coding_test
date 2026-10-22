#include <iostream>

using namespace std;

int n;
int arr[100];
bool dp[100001];
int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    dp[0] = true;

    //sum-a a  sum-a==a

    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= arr[i]; j--) {
            if (dp[j - arr[i]]) dp[j] = true;
        }
    }
    if (sum % 2 != 0) cout << "No";
    else {
        int temp = sum / 2;
        if (dp[temp]) cout << "Yes";
        else cout << "No";
    }
    // Please write your code here.

    return 0;
}
