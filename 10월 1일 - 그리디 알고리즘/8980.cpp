#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    int source, dest, amount;
};

int greedyBox(int n, int m, int c, vector<info> &box){
    vector<int> truck(n, 0);
    int ans = 0; //싣게되는 박스의 총 개수

    for (int i = 0; i < m; i++) {
        int max_loaded = 0;
        //현재 박스의 이동 구간에서 가장 많이 실린 박스의 수
        for (int j = box[i].source; j < box[i].dest; j++)
            max_loaded = max(max_loaded, truck[j]);

        //이번에 실을 수 있는 박스의 수는 트럭의 용량에서 max_loaded를 뺀 값과, 이번 박스의 개수 중 최솟값
        int loaded = min(box[i].amount, c - max_loaded);
        ans += loaded;

        //트럭에 박스 실음
        for (int j = box[i].source; j < box[i].dest; j++)
            truck[j] += loaded;
    }
    return ans;
}

/**
 * 그리디 알고리즘인 이유
 * 조건 3: 박스들 중 '일부'만 배송할 수도 있다.
 *
 * 1. 트럭은 1번 마을부터 출발
 * 2. 트럭에 여유 공간이 많아야 박스를 많이 실을 수 있음
 * -> 도착지가 1번 마을에서 가까운 박스 먼저 싣는다
 * -> 도착지 기준 오름차순 정렬
 */
int main() {
    int n, c, m;

    //입력
    cin >> n >> c >> m;
    vector<info> box(m);
    for (int i = 0; i < m; i++)
        cin >> box[i].source >> box[i].dest >> box[i].amount;

    //연산
    sort(box.begin(), box.end(),
         [](const info &i1, const info &i2) { //익명 함수로 compare 정의
             return i1.dest < i2.dest;
         });

    //연산 & 출력
    cout<<greedyBox(n, m, c, box);
}