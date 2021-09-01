#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * 우선순위 큐에는 가장 큰 수부터 N번째 큰 수까지 N개의 숫자가 들어있는 거라고 생각하세요!
 * 가장 큰 수부터 N번째 큰 수까지를 최소 힙에 넣었으니까 그 우선순위 큐의 root에 있는 값이 N번째 큰 수가 되는거예요
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙

    cin >> n;
    for (int i = 0; i < n * n; i++) {
        //입력
        cin >> input;

        //연산
        if (pq.size() < n) //큐의 크기가 N보다 작다면 그냥 투입
            pq.push(input);
        else if (pq.top() < input) { //큐의 크기가 N이상 이라면 root 노드보다 input이 클 때만 갱신
            pq.pop();
            pq.push(input);
        }
    }

    //출력
    cout << pq.top();
}