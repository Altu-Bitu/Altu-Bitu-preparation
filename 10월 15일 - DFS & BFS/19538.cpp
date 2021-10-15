#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<int> bfs(queue<ci> &q, vector<vector<int>> &people, vector<bool> &visited, vector<int> &ans, int n) {
    vector<int> believed(n + 1, 0); //주변인들이 몇 명 믿는지

    while (!q.empty()) {
        int v = q.front().first; //현재 정점의 사람
        int t = q.front().second; //현재 정점의 시간
        q.pop();
        believed[v]++; //믿은 사람에게 유포 당해서 탐색 하는 것이므로 믿는 주변 사람 수 증가

        bool chk = false;
        //주변인들 중 절반 이상이 루머를 믿고, 아직 본인이 탐색 안 된 경우 -> 루머 믿고 유포 시작
        if ((people[v].size() + 1) / 2 <= believed[v] && !visited[v]) {
            visited[v] = true;
            ans[v] = t; //현재까지 걸린 시간 정답에 저장
            chk = true;
        }
        if (chk || !t) { //현재 루머를 믿게 된 사람 or 최초 유포자
            for (int i = 0; i < people[v].size(); i++) {
                if (!visited[people[v][i]]) {
                    q.push(ci(people[v][i], t + 1));
                }
            }
        }
    }
    return ans;
}

/**
 * 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
 * 방문 체크를 탐색할 때 바로 하는 게 아니라, 루머를 믿게 될 경우 하는 게 중요
 */

int main() {
    ios_base::sync_with_stdio(false); //없어도 되긴 하지만, 없으면 채점 시간이 너무 느리다..
    cin.tie(0);

    queue<ci> q; //인덱스와 시간 저장
    int n, m, input;

    //루머 퍼뜨리는 관계 입력
    cin >> n;
    vector<vector<int>> people(n + 1, vector<int>());
    vector<int> ans(n + 1, -1); //루머를 믿는 시간
    vector<bool> visited(n + 1, false); //방문 체크 배열
    for (int i = 1; i <= n; i++) {
        while (true) {
            cin >> input;
            if (input == 0)
                break;
            people[i].push_back(input);
        }
    }

    //최초 유포자 입력
    cin >> m;
    while (m--) {
        cin >> input;
        q.push(ci(input, 0)); //시작 정점 초기화
        visited[input] = true;
        ans[input] = 0;
    }

    //연산
    ans = bfs(q, people, visited, ans, n);

    //출력
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';

    return 0;
}