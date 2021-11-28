#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;
typedef pair<int, int> ci;

queue<pair<int, ci>> spring(int n, matrix &land, vector<matrix> &tree) {
    queue<pair<int, ci>> dead_tree;
    for (int i = 0; i < n; i++) { //n x n 땅 모두 검사
        for (int j = 0; j < n; j++) {
            sort(tree[i][j].begin(), tree[i][j].end()); //나이가 어린 나무부터
            for (int l = 0; l < tree[i][j].size();) {
                if (land[i][j] - tree[i][j][l] < 0) { //자신의 나이만큼 양분을 먹을 수 없다면
                    dead_tree.push({tree[i][j][l], {i, j}});
                    tree[i][j].erase(tree[i][j].begin() + l);
                    continue;
                }
                land[i][j] -= tree[i][j][l];
                tree[i][j][l]++;
                l++;
            }
        }
    }
    return dead_tree;
}

void summer(queue<pair<int, ci>> &dead_tree, matrix &land) {
    while (!dead_tree.empty()) {
        int temp = dead_tree.front().first; //죽은 나무의 나이
        int r = dead_tree.front().second.first; //죽은 나무의 행 위치
        int c = dead_tree.front().second.second; //죽은 나무의 열 위치
        dead_tree.pop();
        land[r][c] += (temp / 2);
    }
}

void fall(int n, vector<matrix> &tree) {
    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int i = 0; i < n; i++) { //n x n 땅 모두 검사
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < tree[i][j].size(); l++) {
                if (tree[i][j][l] % 5 == 0) { //나이가 5의 배수인 나무
                    for (int o = 0; o < 8; o++) {
                        int nr = i + dr[o];
                        int nc = j + dc[o];
                        if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                            continue;
                        tree[nr][nc].push_back(1);
                    }
                }
            }
        }
    }
}

void winter(int n, matrix &a, matrix &land) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            land[i][j] += a[i][j];
}

int cntSurvive(int n, vector<matrix> &tree) {
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans += tree[i][j].size();

    return ans;
}

/**
 * [문제 설명] - 단순 구현 문제
 * 봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함.
 *    각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음.
 * 여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
 * 가을: 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김.
 * 겨울: 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가
 *
 * K년이 지난 후 상도의 땅에 살아있는 나무의 개수
 *
 * [문제 풀이]
 * land: 땅의 양분
 * a: 로봇(S2D2)가 겨울에 주는 양분의 양
 * tree: 땅에 심은 나무 나이. 한 칸에 여러 나무 심을 수 있으므로 3차원 벡터로 선언.
 *
 * 문제의 설명대로 계절별 연산을 진행.
 */

int main() {
    int n, m, k, x, y, z;

    //입력
    cin >> n >> m >> k;
    matrix a(n, vector<int>(n, 0));
    matrix land(n, vector<int>(n, 5)); //처음 양분 모든 칸에 5
    vector<matrix> tree(n, matrix(n, vector<int>(0)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    while (m--) {
        cin >> x >> y >> z;
        tree[x - 1][y - 1].push_back(z); //(0, 0)부터 시작하도록 구현하기위해 1을 빼준 인덱스에 접근
    }

    //연산
    while (k--) {
        queue<pair<int, ci>> dead_tree = spring(n, land, tree); //봄이 지나고 죽은 나무
        summer(dead_tree, land);
        fall(n, tree);
        winter(n, a, land);
    }

    //출력
    cout << cntSurvive(n, tree);
}