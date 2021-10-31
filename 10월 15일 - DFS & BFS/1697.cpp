#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 100000;

int bfs(int n, int k) {
    vector<bool> visited(SIZE + 1, false);
    queue<ci> q; //큐에 좌표값과 시간을 pair로 저장
    int ans = 0;

    visited[n] = true; //시작 노드 방문체크
    q.push(ci(n, 0)); //시작 노드 초기화
    while (!q.empty()) {
        int x = q.front().first; //현재 탐색하려는 위치
        int t = q.front().second;
        q.pop();

        if (x == k) { //찾으면 탐색 종료
            ans = t;
            break;
        }

        vector<int> child = {x - 1, x + 1, x * 2}; //자식 노드
        for (int i = 0; i < 3; i++) {
            if (child[i] >= 0 && child[i] <= SIZE && !visited[child[i]]) { //범위 내에 있고, 첫 방문이라면
                visited[child[i]] = true;
                q.push(ci(child[i], t + 1));
            }
        }
    }
    return ans;
}

/**
 * x좌표 위에서 x-1, x+1, 2*x의 위치로 계속 이동하며 탐색
 * 가장 빠른 시간을 찾아야 하므로 주변 노드부터 탐색하는 풀이로 풀어서 k에 도달하면 바로 탐색 종료 (bfs)
 */

int main() {
    int n, k;

    //입력
    cin >> n >> k;

    //연산 & 출력
    cout << bfs(n, k) << '\n';

    return 0;
}