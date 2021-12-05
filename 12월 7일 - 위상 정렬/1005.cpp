#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int buildMinimum(int n, int end, vector<int> &delay, vector<int> &sequence, vector<vector<bool>> &graph) {
    vector<int> dp(n + 1, 0); //현재 건물을 짓기까지 총 걸린 시간

    for (int i = 0; i < n; i++) {
        int max_time = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (!graph[sequence[j]][sequence[i]]) //연결되어 있지 않다면
                continue;

            max_time = max(dp[j], max_time); //이어진 전 정점 중 걸린 시간이 가장 긴 건물을 선택 (최대한 동시에 짓는 경우를 고려)
        }
        dp[i] = max_time + delay[sequence[i]];

        if (sequence[i] == end) //문제에서 주어진 건설해야 할 건물이라면
            return dp[i];
    }
}

//위상정렬
vector<int> topological_sort(int n, vector<int> &indegree, vector<vector<bool>> &graph) {
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) //진입차수가 0이라면
            q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 1; i <= n; i++) {
            if (!graph[node][i]) //연결되어 있지 않다면
                continue;

            indegree[i]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[i]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(i);
        }
    }
    return result;
}

int main() {
    int t, n, k, x, y, w;

    //입력
    cin >> t; //테스트 케이스
    while (t--) {
        cin >> n >> k;
        vector<int> indegree(n + 1, 0); //진입차수
        vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, 0)); //그래프
        vector<int> delay(n + 1, 0); //건설에 걸리는 시간
        for (int i = 1; i <= n; i++)
            cin >> delay[i];
        while (k--) {
            cin >> x >> y; //x -> y
            indegree[y]++;
            graph[x][y] = true;
        }
        cin >> w; //승리하기 위해 건설해야 할 건물의 번호

        //위상정렬한 결과
        vector<int> sequence = topological_sort(n, indegree, graph);

        //건설 완료하는데 드는 최소 시간 출력
        cout << buildMinimum(n, w, delay, sequence, graph) << '\n';
    }
    return 0;
}