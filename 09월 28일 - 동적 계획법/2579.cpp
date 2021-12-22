#include <iostream>
#include <vector>

using namespace std;

int maxValue(int n, vector<int> &score) {
    vector<int> dp(n + 1, 0); //각 계단에서의 최댓값 저장

    dp[1] = score[1]; //1번째 계단은 해당 칸 밟는게 최대
    dp[2] = score[1] + score[2]; //2번째 계단은 1번째와 2번째 밟는게 최대
    for (int i = 3; i <= n; i++) { //i - 3연산이 들어가므로 3부터 시작
        //2칸 전에서 온 경우(2칸 이동), 3칸 전 + 2칸 이동해서 1칸 전으로 온 경우(1칸 이동) 중 최댓값
        dp[i] = max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
    }

    return dp[n];
}

/**
 * (튜터용) 다이나믹 풀이를 벡터로 할지 그냥 배열로 할지 고민이에욥..
 * 저는 평소에 최대 SIZE만큼 전역변수로 배열 선언해서 풀긴 하는데 저희가 지금까지 풀이를 거의 벡터사용으로 해왔으니까..우선 통일을 했습니다..!
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> score(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> score[i];

    //연산 + 출력
    cout << maxValue(n, score);

    return 0;
}