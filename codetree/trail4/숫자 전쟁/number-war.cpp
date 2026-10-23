#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> first_cards(n), second_cards(n);
    for (int i = 0; i < n; i++) cin >> first_cards[i];
    for (int i = 0; i < n; i++) cin >> second_cards[i];

    // dp[i][j] = 상대 맨 위가 i번째, 남우 맨 위가 j번째일 때
    //            여기서부터 끝까지 남우가 얻을 수 있는 최대 점수
    // i == n 또는 j == n이면 게임 끝 → 0 (vector 초기값)
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            // 카드 버리기 (항상 가능, 같은 카드 대결도 결과 동일)
            dp[i][j] = dp[i + 1][j + 1];

            // 남우 카드가 더 작음 → 남우 카드 버리고 점수 획득
            if (second_cards[j] < first_cards[i])
                dp[i][j] = max(dp[i][j], dp[i][j + 1] + second_cards[j]);

            // 상대 카드가 더 작음 → 상대 카드 버림
            if (first_cards[i] < second_cards[j])
                dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        }
    }

    cout << dp[0][0];
    return 0;
}
