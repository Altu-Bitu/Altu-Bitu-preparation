#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 26;

//위상정렬 + DP
int topologicalSort(vector<int> &days, vector<int> &indegree, vector<vector<int>> &graph) {
    vector<int> result;
    queue<int> q;
    vector<int> dp(SIZE, 0); //현재 작업 하기까지 걸린 시간
    int ans = 0;

    for (int i = 0; i < SIZE; i++) {
        dp[i] = days[i]; //dp 배열 초기화
        if (days[i] && !indegree[i]) //진입차수가 0이라면
            q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        result.push_back(node); //현재 정점 순서에 삽입
        ans = max(ans, dp[node]); //정답 갱신 (마지막 정점이 result의 마지막 정점이 아닐 수 있음)
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node);

            //다음 정점의 최소 시간 계산 -> 이어진 전 정점 중 가장 긴 시간의 정점을 선택
            dp[next_node] = max(dp[next_node], dp[node] + days[next_node]);
        }
    }
    return ans;
}

int main() {
    vector<int> indegree(SIZE, 0);
    vector<vector<int>> graph(SIZE, vector<int>(0));
    vector<int> days(SIZE, 0), check(SIZE, 0);
    string input;

    //입력
    while (getline(cin, input)) {
        char work = input[0];
        string temp = "", prev = "";
        int day = 0;
        for (int i = 2; i < input.length(); i++) {
            if (input[i] == ' ' && day == 0) {
                day = stoi(temp);
                temp = "";
                continue;
            }
            temp += input[i];
        }
        if (day)
            prev = temp;
        else
            day = stoi(temp);

        indegree[work - 'A'] = prev.length();
        days[work - 'A'] = day;
        for (int i = 0; i < prev.length(); i++)
            graph[prev[i] - 'A'].push_back(work - 'A');
    }
    cout << topologicalSort(days, indegree, graph);
}