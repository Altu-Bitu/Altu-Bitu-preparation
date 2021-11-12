#include <iostream>
#include <vector>

using namespace std;
const int INF = INT32_MAX;

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

    if (tree[node].empty())
        return dp[node][flag] = flag ? sales[node - 1] : 0;
    dp[node][flag] = 0; //초기화
    bool attend_flag = false; //부하직원 중 한 명이라도 참석했나?
    int diff = INF;
    for (int i = 0; i < tree[node].size(); i++) {
        int next_node = tree[node][i];
        int attend = fillDp(sales, tree, next_node, true);
        int nonattendance = fillDp(sales, tree, next_node, false);
        dp[node][flag] += min(attend, nonattendance);
        if (attend < nonattendance)
            attend_flag = true;
        diff = min(diff, attend - nonattendance);
    }
    if (flag)
        return dp[node][flag] += sales[node - 1];
    if (!attend_flag)
        return dp[node][flag] += diff;
    return dp[node][flag];
    if (flag) { //node번 직원 참석
        int cost = 0;
        for (int i = 0; i < tree[node].size(); i++) {
            int next_node = tree[node][i]; //부하직원

            //모든 부하직원은 참석해도, 참석하지 않아도 상관없음
            cost += min(fillDp(sales, tree, next_node, true),
                        fillDp(sales, tree, next_node, false));
        }
        //부하직원의 참석여부에 따른 비용(cost) + 본인의 참석 비용(sales[node-1])
        return dp[node][flag] = cost + sales[node - 1];
    }
    //node번 직원 불참
    int cost = INF;
    for (int i = 0; i < tree[node].size(); i++) {
        int tmp_cost = 0;

        //각 팀에서 1명 이상은 참석해야 하므로 부하직원 중 한 명은 반드시 참석해야 함
        //j번째 부하직원이 반드시 참여하도록
        for (int j = 0; j < tree[node].size(); j++) {
            int next_node = tree[node][j]; //부하직원
            if (i == j) //반드시 참여해야 하는 직원
                tmp_cost += fillDp(sales, tree, next_node, true);
            else //참여여부 상관없는 직원
                tmp_cost += min(fillDp(sales, tree, next_node, true),
                                fillDp(sales, tree, next_node, false));
        }
        cost = min(cost, tmp_cost); //최솟값 갱신
    }
    //cost가 갱신되지 않음 == tree[node].empty() == 부하직원이 없음(말단직원)
    if (cost == INF)
        cost = 0;
    //부하직원의 참석여부에 따른 비용(cost)
    return dp[node][flag] = cost;
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