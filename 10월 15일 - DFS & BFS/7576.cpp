#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci; //row, col 저장하기 위한 pair

int bfs(int n, int m, int cnt, vector<vector<int>> &matrix, queue<ci> q) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int t = 0;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        t = matrix[cr][cc]; //현재 탐색까지 걸린 시간
        cnt--; //익은 토마토 감소
        for (int i = 0; i < 4; i++) { //상, 하, 좌, 우 방향 탐색 (인접한 노드 탐색)
            int nr = cr + dx[i]; //탐색하려는 임시 노드
            int nc = cc + dy[i]; //탐색하려는 임시 노드
            if (nr > 0 && nr <= n && nc > 0 && nc <= m && matrix[nr][nc] == 0) { //노드가 존재(행렬 범위 안에 있음)하며, 익지 않은 토마토라면
                matrix[nr][nc] = matrix[cr][cc] + 1; //시간 증가값을 토마토 행렬에 저장
                q.push(ci(nr, nc));
            }
        }
    }

    if (!cnt) //모든 토마토 익었다면
        return t - 1;
    return -1;
}

int main() {
    int n, m;
    queue<ci> q; //bfs 탐색을 위한 토마토 위치 저장 큐

    //토마토
    cin >> m >> n;
    int cnt = n * m; //전체 토마토 개수 (나중에 탐색 종료 조건에 활용)
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0)); //토마토 정보 저장
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) //익은 토마토 바로 삽입 (시작 노드)
                q.push(ci(i, j));
            else if (matrix[i][j] == -1) //토마토 없다면 전체에서 감소
                cnt--;
        }
    }

    //bfs 탐색 & 출력
    cout << bfs(n, m, cnt, matrix, q);

    return 0;
}