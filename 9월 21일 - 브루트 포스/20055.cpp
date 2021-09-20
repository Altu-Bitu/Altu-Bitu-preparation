#include <iostream>
#include <vector>

using namespace std;

int zero_power;  //내구도가 0인 벨트 칸의 개수

int minusPosition(int n, int pos) { //인덱스 감소
    if (--pos >= 0)
        return pos;
    return n * 2 - 1;
}

void second(int n, int start, int end, vector<bool> &robot, vector<int> &power) {
    int idx = end;
    while(idx != start) { //end - 1 부터 start 까지 검사
        idx = minusPosition(n, idx);
        int next = (idx + 1) % (n * 2); //다음 위치
        if (robot[idx] && !robot[next] && power[next]) { //현재 위치에 로봇이 있고, 다음 위치에 로봇이 없으며 내구성 1이상인 경우 -> 로봇 옮김
            robot[idx] = false;
            power[next]--;
            if (next != end) //내리는 위치 아닐 경우만
                robot[next] = true; //로봇 옮기기
            if (power[next] == 0)
                zero_power++;
        }
    }
}

void third(int start, vector<bool> &robot, vector<int> &power) {
    if (power[start]) { //올리는 위치의 내구도가 0이 아니라면 로봇 올림
        robot[start] = true;
        power[start]--;
        if (power[start] == 0)
            zero_power++;
    }
}

/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근
 * 필요한 컨테이너: 로봇의 존재여부 체크 배열, 내구도 저장한 배열
 * 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 * 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 내리는 위치 - 1 부터 올리는 위치 + 1까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 * 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    //입력
    cin >> n >> k;

    vector<bool> robot(n * 2, false); //로봇의 존재여부 체크
    vector<int> power(n * 2, 0);      //내구도 저장
    for (int i = 0; i < n * 2; i++)
        cin >> power[i];

    //연산
    int start = 0;   //올리는 위치
    int end = n - 1; //내리는 위치
    int ans = 0;     //단계 수
    while (true) {
        start = minusPosition(n, start);
        end = minusPosition(n, end);
        if (robot[end]) //로봇이 내리는 위치에 있다면 내리기
            robot[end] = false;
        second(n, start, end, robot, power);
        third(start, robot, power);
        ans++;
        if (zero_power >= k)
            break;
    }

    //출력
    cout << ans << '\n';

    return 0;
}