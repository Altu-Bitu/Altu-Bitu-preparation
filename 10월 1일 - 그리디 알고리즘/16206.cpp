#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

//롤케이크 자르는 함수
void cutRollCake(int &m, int &ans, priority_queue<int, vector<int>, greater<int>> pq) {
    while (m > 0 && !pq.empty()) {
        int len = pq.top();
        pq.pop();
        int divide_len = len - 10; //길이 10 우선 자름
        ans++;
        m--;
        if (divide_len == 10) //남은 길이가 10이라면
            ans++;
        else if (divide_len > 10)
            pq.push(divide_len);
    }
}

/**
 * 길이가 10인 롤케이크 개수의 최댓값을 구하는 문제
 * 길이가 10이상인 롤케이크를 잘라보자. 길이가 10이상이면 하나 이상을 만드는 것이므로, 길이가 작은 것부터 잘라보자
 * 이때, 10으로 나누어 떨어지는 길이를 먼저 잘라야 한다 (ex. 15를 한 번 자르면 1개가 생기지만, 20을 한 번 자르면 2개가 생김)
 */

int main() {
    int n, m, roll, ans = 0;

    //입력
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> pq_10, pq;
    for (int i = 0; i < n; i++) {
        cin >> roll;
        if (roll < 10)
            continue;
        if (roll == 10)
            ans++;
        else if (roll % 10 == 0)
            pq_10.push(roll);
        else
            pq.push(roll);
    }

    //연산
    cutRollCake(m, ans, pq_10);
    cutRollCake(m, ans, pq);

    //출력
    cout << ans << '\n';

    return 0;
}