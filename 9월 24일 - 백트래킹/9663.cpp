#include <iostream>

using namespace std;

const int SIZE = 15;

int n, ans;
bool check_col[SIZE];     //열
bool check_left[SIZE*2];  //왼쪽 대각선
bool check_right[SIZE*2]; //오른쪽 대각선

void backtracking(int cnt) { //cnt: 행
    if (cnt == n) { //끝 행(n)까지 옴 -> 퀸의 개수가 n개 놓였다는 것
        ans++; //정답 증가
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!check_col[i] && !check_left[cnt + i] && !check_right[cnt - i + n]) { //조건에 맞는 경우만 탐색 (가지치기)
            //퀸이 놓임을 표시 -> 즉 해당 열, 왼쪽대각선, 오른쪽대각선엔 더 이상 퀸이 놓일 수 없음
            check_col[i] = true;
            check_left[cnt + i] = true;
            check_right[cnt - i + n] = true;
            //다음 행 호출
            backtracking(cnt + 1);
            //다시 return 되었을 때, 원래 상태로 돌려놓기
            check_col[i] = false;
            check_left[cnt + i] = false;
            check_right[cnt - i + n] = false;
        }
    }
}

int main() {
    //입력
    cin >> n;

    //연산
    backtracking(0);

    //출력
    cout << ans << '\n';

    return 0;
}