#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
const double INF = 1e3;
typedef pair<double, int> ci;

double prim(int v, int start, vector<vector<ci>> &graph) {
    double sum = 0;
    vector<double> dist(v, INF); //각 정점까지의 비용
    vector<bool> visited(v, false); //정점 방문 여부 (다익스트라와 달리 프림에선 필요!)
    priority_queue<ci, vector<ci>, greater<>> pq;

    //초기화
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        double cost = pq.top().first; //간선 가중치
        int cur = pq.top().second; //현재 정점
        pq.pop();

        if (visited[cur]) //이미 확인했던 정점
            continue;
        sum += cost; //MST 간선 가중치 총합
        visited[cur] = true; //방문 처리

        for (int i = 0; i < graph[cur].size(); i++) {
            double next_cost = graph[cur][i].first;
            int next_node = graph[cur][i].second;
            if (!visited[next_node] && next_cost < dist[next_node]) { //미방문 정점이면서 더 짧은 간선을 통해 갈 수 있다면
                dist[next_node] = next_cost;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    return sum;
}

int main() {
    int n;

    //입력
    cin >> n;
    vector<vector<ci>> graph(n, vector<ci>(0));
    vector<pair<double, double>> stars(n);
    for (int i = 0; i < n; i++)
        cin >> stars[i].first >> stars[i].second;

    //연산
    //임의의 두 별에 대한 거리(간선) 모두 구하기
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double xd = stars[i].first - stars[j].first;
            double yd = stars[i].second - stars[j].second;
            double dist = sqrt(xd * xd + yd * yd);
            graph[i].emplace_back(dist, j);
            graph[j].emplace_back(dist, i);
        }
    }

    //연산 & 출력
    cout << fixed;
    cout.precision(2);
    cout << prim(n, 0, graph);
}