#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef pair<int, int> ci;

//위상정렬 + DP
map<int, int> topologicalSort(int n, vector<int> &indegree, vector<vector<ci>> &graph) {
    vector<int> result;
    queue<int> q;
    map<int, int> basic; //기본 부품

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) { //진입차수가 0이라면 -> 기본 부품
            q.push(i);
            basic.insert({i, 0});
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int cnt = graph[node][i].second; //필요한 node 부품 수
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node);
        }
    }
    return basic;
}

/**
 * 각 부품별 필요 개수 구하는 부분이 조금 까다로워서 (?) dp적 개념이 조금 있어서 좋다
 */

int main() {
    int n, m, x, y, k;

    //입력
    cin >> n >> m;
    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    vector<int> indegree(n + 1, 0);
    while (m--) {
        cin >> x >> y >> k; //y -> x
        indegree[x]++;
        graph[y].push_back({x, k});
    }

    //연산
    map<int, int> result = topologicalSort(n, indegree, graph);

    //출력
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        cout << iter->first << ' ' << iter->second << '\n';
    }
    return 0;
}