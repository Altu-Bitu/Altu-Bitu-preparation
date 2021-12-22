#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;
const int INF = 1e6 * 5;

vector<ll> bellmanFord(int n, int m, int start, vector<ti> &edges) {
    //오버플로우 X, 언더플로우 O
    //500 * 6,000 * (-10,000) => int 범위 넘어감!
    vector<ll> dist(n + 1, INF);
    bool flag = true; //(튜터용) 이거 버블정렬때 더이상 안변하면 break 했던 것과 같은 원리라는 설명을 하려구요!

    dist[start] = 0; //시작 위치 초기화

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            //s->d인 간선의 가중치가 w
            int s = get<0>(edges[j]);
            int d = get<1>(edges[j]);
            int w = get<2>(edges[j]);

            if (dist[s] == INF) //아직 시작점에서 s로 가는 경로가 발견되지 않았으므로 갱신할 수 없음
                continue;
            ll next_weight = w + dist[s];
            if (dist[d] > next_weight) { //더 짧은 경로로 갈 수 있다면
                if (i == n) //n번째 갱신이었다면 음의 사이클 발생
                    return {INF + 1};
                dist[d] = next_weight;
                flag = false;
            }
        }
        if (flag) //더이상 갱신되지 않았다면 더 탐색할 필요 없음
            break;
    }
    return dist;
}

int main() {
    int n, m, a, b, c;

    //입력
    cin >> n >> m;
    vector<ti> edges(m); //그래프 관계보단 각각의 간선 정보가 더 중요!
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges[i] = {a, b, c}; //방향 그래프
    }

    //연산
    vector<ll> ans = bellmanFord(n, m, 1, edges);

    //출력
    if (ans[0] == INF + 1) { //음의 사이클
        cout << -1;
        return 0;
    }
    for (int i = 2; i <= n; i++)
        cout << ((ans[i] == INF) ? -1 : ans[i]) << '\n';
}