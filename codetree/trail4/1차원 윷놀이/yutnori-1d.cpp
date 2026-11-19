#include <iostream>

using namespace std;

int n, m, k;
int nums[12];
int chose[12];

int ans = -1;
void go(int idx) {

    if (idx == n) {
        //다 골랐지
        //이제 더 해줘야지
        int hores[5] = {0,};
        for (int i = 0; i < n; i++) hores[chose[i]] += nums[i];
        //chose[idx] 위치에 더해줘야지

        int sum = 0;
        for (int i = 0; i < k; i++) if (hores[i] >= m - 1) sum++;
        ans = max(ans, sum);
        return;
    }
    //idx마다 고르는게 뭐야
    //어떤 k에 들어갈지

    for (int i = 0; i < k; i++) {
        chose[idx] = i;
        go(idx + 1);
    }

}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Please write your code here.
    go(0);
    cout << ans;

    return 0;
}
//K개의 말 M에 도착하면 1점
//N번 던진거야
//1+숫자의 조합이 M이상이면 되는거지
//a번 말에 조합 x개를 던져 그리고 최대 몇개가 되는지

//idx -->몇번째에 적용할지
//그냥 k개가 있고 k개에 더할지 말지 결정
