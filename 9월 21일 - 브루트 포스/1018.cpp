#include <iostream>
#include <vector>

using namespace std;

//(row, cal) 에서 시작하는 8 * 8 체스판 만드는 데 드는 최소 카운트 리턴
int chessChange(int row, int cal, vector<vector<char>> &board) {
    int w_cnt = 0; //W로 시작하는 체스판 만들기 위한 카운트
    int b_cnt = 0; //B로 시작하는 체스판 만들기 위한 카운트

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) { //시작 인덱스 (0,0)을 기준으로 행+열 값이 짝수면 시작색과 동일
                if (board[row + i][cal + j] != 'B')
                    b_cnt++;
                else
                    w_cnt++;
            } else { //홀수면 시작색과 다른 색
                if (board[row + i][cal + j] != 'W')
                    b_cnt++;
                else
                    w_cnt++;
            }
        }
    }

    return min(w_cnt, b_cnt); //최솟값 리턴
}

int main() {
    int n, m, ans = -1;

    //입력
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m)); //행: n, 열: m
    for (int i = 0; i < n; i++) //보드 입력
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    //연산
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            int cnt = chessChange(i, j, board); //시작이 (i,j)인 체스판 만드는 최솟값
            if (ans > cnt || ans == -1) //cnt가 더 작거나 ans에 값 저장이 처음이라면
                ans = cnt; //최솟값 갱신
        }
    }

    //출력
    cout << ans << '\n';

    return 0;
}