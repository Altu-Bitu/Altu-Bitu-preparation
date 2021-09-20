#include <iostream>

using namespace std;

const int SIZE = 15;

int n, ans;
bool check_col[SIZE];     //열
bool check_left[SIZE*2];  //왼쪽 대각선
bool check_right[SIZE*2]; //오른쪽 대각선

void backtracking(int row) { //row: 행
    if (row == n) { //끝 행(n)까지 옴 -> 퀸의 개수가 n개 놓였다는 것
        ans++; //정답 증가
        return;
    }
    for (int col = 0; col < n; col++) {
        if (!check_col[col] && !check_left[row + col] && !check_right[row - col + n]) { //조건에 맞는 경우만 탐색 (가지치기)
            //퀸이 놓임을 표시 -> 즉 해당 열, 왼쪽대각선, 오른쪽대각선엔 더 이상 퀸이 놓일 수 없음
            check_col[col] = true;
            check_left[row + col] = true;
            check_right[row - col + n] = true;
            //다음 행 호출
            backtracking(row + 1);
            //다시 return 되었을 때, 원래 상태로 돌려놓기
            check_col[col] = false;
            check_left[row + col] = false;
            check_right[row - col + n] = false;
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