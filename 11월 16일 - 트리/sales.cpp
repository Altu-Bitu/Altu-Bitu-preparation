#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

vector<vector<int>> makeTree(int n, vector<vector<int>> &links) {
    vector<vector<int>> tree(n, vector<int>(0));
    for (int i = 0; i < links.size(); i++)
        tree[links[i][0]].push_back(links[i][1]);
    return tree;
}

int fillDp(vector<int> &sales, vector<vector<int>> &tree, int node, bool flag) {
    if (dp[node][flag] != -1) //이미 탐색했던 상태
        return dp[node][flag];

    //(튜터용) 이 부분은 맨 마지막에 추가하려구요!
    if (tree[node].empty()) //말단직원
        return dp[node][flag] = flag ? sales[node - 1] : 0;

    dp[node][flag] = 0; //초기화
    bool attend_flag = false; //부하직원 중 한 명이라도 참석했나?
    int diff = INT32_MAX;
    for (int i = 0; i < tree[node].size(); i++) {
        int next_node = tree[node][i]; //부하직원
        int attend = fillDp(sales, tree, next_node, true); //참석하는 경우
        int absent = fillDp(sales, tree, next_node, false); //불참하는 경우

        dp[node][flag] += min(attend, absent); //더 작은 값 더하기
        //(튜터용) line 33~35도 상대적으로 늦게 추가하겠습니다!
        if (attend < absent) //부하직원이 한 명이라도 참석한 경우
            attend_flag = true;
        diff = min(diff, attend - absent); //모든 팀원이 불참했을 때를 대비
    }
    if (flag) //팀장 참석
        return dp[node][flag] += sales[node - 1];
    if (!attend_flag) //팀장 + 부하직원 모두 불참
        return dp[node][flag] += diff; //부하직원이 참석한 경우 중 매출 차이가 제일 적었던 경우를 더함
    return dp[node][flag];
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int v = sales.size();
    dp.assign(v + 1, vector<int>(2, -1));
    vector<vector<int>> tree = makeTree(v + 1, links); //트리 만들기

    //CEO가 참석하는 경우, CEO가 참석하지 않는 경우
    return min(fillDp(sales, tree, 1, true), fillDp(sales, tree, 1, false));
}

int main() {
    vector<int> sales = {14, 17, 15, 18, 19, 14, 13, 16, 28, 17};
    vector<vector<int>> links = {{10, 8},
                                 {1,  9},
                                 {9,  7},
                                 {5,  4},
                                 {1,  5},
                                 {5,  10},
                                 {10, 6},
                                 {1,  3},
                                 {10, 2}};
    int ans = solution(sales, links);
    cout << ans;
}