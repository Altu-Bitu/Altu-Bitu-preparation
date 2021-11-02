#include <iostream>

using namespace std;
typedef pair<string, string> ci;
const int SIZE = 8;

int direction(string move) {
    if (move == "L") return 0;
    if (move == "R") return 1;
    if (move == "B") return 2;
    if (move == "T") return 3;
    if (move == "LT") return 4;
    if (move == "LB") return 5;
    if (move == "RT") return 6;
    if (move == "RB") return 7;
}

ci moveKing(string move, string king, string rock) {
    //상, 하, 좌, 우, 우상향, 좌상향, 우하향, 좌하향
    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[8] = {0, 0, -1, 1, 1, -1, 1, -1};
    int d = direction(move); //방향 인덱스 저장
    ci ans = {king, rock};

    int rock_r = rock[0] - 'A';
    int rock_c = rock[1] - '1';
    int king_nr = (king[0] - 'A') + dr[d];
    int king_nc = (king[1] - '1') + dc[d];
    if (king_nr >= 0 && king_nr < SIZE && king_nc >= 0 && king_nc < SIZE) { //킹이 범위 안이라면
        ans.first = (king_nr + 'A');
        ans.first += (king_nc + '1');
        if (king_nr != rock_r || king_nc != rock_c) //돌이 없다면
            return ans;

        int rock_nr = rock_r + dr[d];
        int rock_nc = rock_c + dc[d];
        if (rock_nr >= 0 && rock_nr < SIZE && rock_nc >= 0 && rock_nc < SIZE) {
            ans.second = (rock_nr + 'A');
            ans.second += (rock_nc + '1');
            return ans;
        }
        ans.first = king; //돌이 범위를 넘어가서 다시 원래 자리로 되돌림
    }
    return ans; //킹과 돌의 마지막 위치 리턴
}

/**
 * 체스판을 편하게 구현하기 위해 왼쪽 아래를 시계방향으로 90도 회전한 체스판으로 구현
 * [방향 바꿔서 생각]
 *  T:상 -> 우       B:하 -> 좌       L:좌->상         R:우->하
 * RT:오위 -> 오아   LT:왼위 -> 오위   RB:오아 -> 왼아   LB:왼아 -> 왼위
 *
 * => 바뀐 방향대로 입력에 따라 킹과 돌을 움직임
 *
 * [경우의 수]
 * 1. 킹이 범위를 벗어나는 경우
 * 2. 킹이 움직이는 방향에 돌이 없는 경우
 * 3. 킹이 움직이는 방향에 돌이 있고, 돌이 범위를 벗어나는 경우
 * 4. 킹이 움직이는 방향에 돌이 있고, 둘 다 범위를 벗어나지 않는 경우
 *
 */

int main() {
    string king, rock, move;
    int n;

    //입력 & 연산
    cin >> king >> rock >> n;
    ci ans = {king, rock}; //초기 킹, 돌 위치
    while (n--) {
        cin >> move;
        ans = moveKing(move, ans.first, ans.second);
    }

    //출력
    cout << ans.first << '\n' << ans.second << '\n';
    return 0;
}