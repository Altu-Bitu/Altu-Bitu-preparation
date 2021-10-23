#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7; //최대 n-1개의 간선을 지나게 됨

void floydWarshall(int n, vector<vector<int>> &graph) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                int dist = graph[j][i] + graph[i][k]; //중간에 i를 거쳐서 j에서 k로 감
                if (graph[j][k] > dist) //j->k보다 j->i->k가 더 짧은 경로
                    graph[j][k] = dist;
            }
        }
    }
}

int main() {
    int n, m, a, b, c;

    //입력
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) //자기 자신과의 거리
        graph[i][i] = 0;

    while (m--) {
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c); //중복 간선이 들어올 수 있으므로 가장 작은 값만 사용
    }

    //연산
    floydWarshall(n, graph);

    //출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << ((graph[i][j] == INF) ? 0 : graph[i][j]) << ' ';
        cout << '\n';
    }
}