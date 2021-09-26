#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

int maxMoney(int n, vector<ci> &counsel) {
    vector<int> dp(n + 2, 0);

    //i번째 날에 대한 상담 최댓값 구하기
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1]); //우선 i번째 상담 안하는 경우
        if (i + counsel[i].first <= n + 1) { //i번째 상담이 가능한 경우
            dp[i + counsel[i].first] = max(dp[i + counsel[i].first], dp[i] + counsel[i].second);
        }
    }

    return max(dp[n], dp[n + 1]);
}

/**
 * 1번째 날부터 시작하여 i번째 날에 대한 상담 최댓값 저장하기
 * 현재 날을 상담하는 걸 택하면 현재 날에 상담이 걸리는 날을 더한 날의 최댓값이 변경됨
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<ci> counsel(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> counsel[i].first >> counsel[i].second;
    }

    //연산 + 출력
    cout << maxMoney(n, counsel) << '\n';

    return 0;
}