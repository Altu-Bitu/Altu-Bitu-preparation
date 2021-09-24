#include <iostream>

using namespace std;

const int SIZE = 10;

int n, m;
int num[SIZE];
bool check[SIZE];

//백트래킹을 위한 재귀함수
void backtracking(int cnt) {
    if (cnt == m) { //기저조건
        for (int i = 0; i < cnt; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return; //남아있는 경우의 수 검사하기 위해 다시 전 단계로 넘어감
    }
    for (int i = 1; i <= n; i++) {
        if (!check[i]) { //사용한 수 제외하고 탐색 (가지치기)
            check[i] = true; //사용했음을 표시
            num[cnt] = i;
            backtracking(cnt + 1); //다음 인덱스 호출
            check[i] = false; //다시 돌아오면, 원래 상태로 되돌려 놓음
        }
    }
    //반복문이 끝나고, 전 단계가 남아있다면 자동으로 return 됨
}

int main() {
    //입력
    cin >> n >> m;

    //연산 + 출력
    backtracking(0);

    return 0;
}