#include <iostream>
#include <vector>

using namespace std;

struct info {
    int w, v;
};

vector<info> product;

//2차원 냅색
int knapsack_2(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) { //각 물품에 대해, i: 물품 번호
        for (int j = 1; j <= k; j++) { //j: 최대 배낭 무게
            if (j - product[i].w >= 0) //해당 물품 배낭에 넣는게 가능하다면 -> 배낭에 넣는 경우와 안 넣는 경우 중 최댓값 저장
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - product[i].w] + product[i].v);
            else //불가능하면 무조건 배낭에 안넣는 값 저장 (그 전 물품에 대한 현재 무게의 최댓값)
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][k];
}

//1차원 냅색
int knapsack_1(int n, int k) {
    vector<int> dp(k + 1, 0);

    for (int i = 1; i <= n; i++) { //i: 물품 번호
        for (int j = k; j >= product[i].w; j--) { //j: 최대 배낭 무게, 1차원이니 무게 k부터 시작(거꾸로)
            dp[j] = max(dp[j], dp[j - product[i].w] + product[i].v); //배낭에 넣는 경우와 안 넣는 경우 중 최댓값 저장
        }
    }

    return dp[k];
}

/**
 * (튜터용)
 * 이 문제 처음엔 2차원 배열(knapsack_2)로 구현했다 1차원(knapsack_1)으로 바꾸는 거 보여줄 예정입니다!
 *
 * 뭔가 벡터로 하니까 선언도 길어지고 더 헷갈리는 것 같기도 하네여....벡터랑..배열..뭐가 좋을까요 ,,,!
 */

int main() {
    int n, k;

    //입력
    cin >> n >> k;
    product.assign(n + 1, {});
    for (int i = 1; i <= n; i++) { //각 물품의 무게와 가치 입력
        cin >> product[i].w >> product[i].v;
    }

    //연산 + 출력
    cout << knapsack_1(n, k) << '\n';

    return 0;
}