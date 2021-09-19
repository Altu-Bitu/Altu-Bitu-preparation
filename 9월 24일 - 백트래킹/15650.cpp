#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;

int n, m;
int num[SIZE];

//백트래킹을 위한 재귀함수
void backtracking(int cnt, int start) {
    if (cnt == m) { //기저조건
        for (int i = 0; i < cnt; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return; //남아있는 경우의 수 검사하기 위해 다시 전 단계로 넘어감
    }
    for (int i = start; i <= n; i++) { //시작인덱스부터 탐색
        num[cnt] = i;
        backtracking(cnt + 1, i + 1); //다음 인덱스 호출, 현재인덱스 + 1을 보내줌
    }
    //반복문이 끝나고, 전 단계가 남아있다면 자동으로 return 됨
}

/**
 * (튜터용)
 * 현지님께서 제안해주신대로 처음엔 N과M(1)코드처럼 check배열 사용 그대로 나두었다가,
 * 매개변수 만들고 나중에 check배열 없앨 예정입니다!
 */

int main() {
    //입력
    cin >> n >> m;

    //연산 + 출력
    backtracking(0, 1);

    return 0;
}