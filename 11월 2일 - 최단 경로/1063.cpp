#include <iostream>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 8;

string pointToString(ci point) {
    string ans;
    ans = (point.first + 'A');
    ans += (point.second + '1');
    return ans;
}

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

pair<ci, ci> moveKing(string move, ci point_k, ci point_r) {
    //상, 하, 좌, 우, 우상향, 좌상향, 우하향, 좌하향
    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[8] = {0, 0, -1, 1, 1, -1, 1, -1};
    int d = direction(move); //방향 인덱스 저장

    int king_nr = point_k.first + dr[d];
    int king_nc = point_k.second + dc[d];
    if (king_nr >= 0 && king_nr < SIZE && king_nc >= 0 && king_nc < SIZE) { //킹이 범위 안이라면
        if (king_nr != point_r.first || king_nc != point_r.second) { //돌이 없다면
            point_k = {king_nr, king_nc};
            return {point_k, point_r};
        }
        //돌이 있다면
        int rock_nr = point_r.first + dr[d];
        int rock_nc = point_r.second + dc[d];
        if (rock_nr >= 0 && rock_nr < SIZE && rock_nc >= 0 && rock_nc < SIZE) {
            point_k = {king_nr, king_nc};
            point_r = {rock_nr, rock_nc};
        }
    }
    return {point_k, point_r};
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
    ci point_k = {king[0] - 'A', king[1] - '1'}; //초기 킹 위치
    ci point_r = {rock[0] - 'A', rock[1] - '1'}; //초기 돌 위치
    pair<ci, ci> point = {point_k, point_r};
    while (n--) {
        cin >> move;
        point = moveKing(move, point.first, point.second);
    }

    //출력
    cout << pointToString(point.first) << '\n' << pointToString(point.second) << '\n';
    return 0;
}