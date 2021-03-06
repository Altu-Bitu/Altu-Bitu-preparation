#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    int N;

    //입력
    cin >> N;
    for (int i = 1; i <= N; i++)
        q.push(i);

    //연산
    //반복문 탈출 조건 : 큐에 카드가 1장 남음
    while (q.size() != 1) {
        //위에 있는 카드 버리기
        q.pop(); //반복문을 도는 동안 큐의 크기는 항상 1보다 크기 때문에 empty 체크를 할 필요 없음

        //위에 있는 카드 맨 아래로 옮기기
        int card = q.front();
        q.pop();
        q.push(card);
    }

    //출력
    cout << q.front();
}