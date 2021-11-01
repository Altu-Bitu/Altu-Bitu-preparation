#include <iostream>
#include <vector>

using namespace std;

void floydWarshall(int n, vector<vector<bool>> &matrix) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (!matrix[i][k]) //i->k 전후관계 없는 경우
                continue;
            for (int j = 1; j <= n; j++) {
                if (!matrix[k][j]) //k->j 전후관계 없는 경우
                    continue;
                matrix[i][j] = true; //중간에 k를 거쳐서 i에서 j로 감. 즉, i->j 전후관계 생김
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, s, a, b;

    //입력
    cin >> n >> k;
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
    while (k--) {
        cin >> a >> b;
        graph[a][b] = true; //전후관계 -> 단방향 그래프
    }

    //연산
    floydWarshall(n, graph);

    //입력 & 출력
    cin >> s;
    while (s--) {
        cin >> a >> b;
        if (graph[a][b])
            cout << "-1";
        else if (graph[b][a])
            cout << "1";
        else
            cout << "0";
        cout << '\n';
    }
    return 0;
}