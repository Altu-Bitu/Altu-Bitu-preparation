#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e8; //최대 n-1개의 간선을 지나게 됨

//역추적
vector<int> back(int x, vector<int> &path) { //x: 도착점부터 경로 탐색
    vector<int> result(0); //경로 저장할 벡터
    while (x != 0) {
        result.push_back(x);
        x = path[x]; //다음 경로
    }
    return result;
}

//다익스트라
int dijkstra(int n, int s, int e, vector<vector<ci>> &graph, vector<int> &path) {
    vector<int> dist(n + 1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    //시작 위치 초기화
    dist[s] = 0;
    pq.push(ci(0, s));

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) //이미 더 짧은 경로가 있다면 (없으면 시간초과)
            continue;

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 연결된 정점까지의 거리
            if (dist[next_node] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[next_node] = next_weight;
                path[next_node] = node; //경로 저장
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist[e];
}

/**
 * 다익스트라 역추적
 * - 기본 문제: 최소 비용 구하기
 */

int main() {
    int n, m, a, b, c, s, e;

    //입력
    cin >> n >> m;
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //인접 리스트
    vector<int> path(n + 1, 0); //경로 저장
    while (m--) {
        cin >> a >> b >> c;
        graph[a].push_back(ci(b, c)); //방향 그래프
    }
    cin >> s >> e;

    //연산
    int ans = dijkstra(n, s, e, graph, path);
    vector<int> result = back(e, path);

    //출력
    cout << ans << '\n' << result.size() << '\n';
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' ';

    return 0;
}