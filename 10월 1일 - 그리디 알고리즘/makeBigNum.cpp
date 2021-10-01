#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 정답은 (number의 길이 - k)만큼의 길이로 이루어짐
 * 정답의 길이만큼 큰 수를 만들어가는 과정을 생각하자
 * 즉, 정답의 0번 인덱스부터 마지막 인덱스의 값까지 차례로 하나씩 구해나간다
 * 이는 시작 위치 = 0, 끝 위치 = k인 구역부터 시작해서 각각 가장 큰 값을 찾아가는 과정을 (number의 길이 - k)만큼 반복하면 된다
 *
 * 이러한 그리디적 풀이가 가능한 이유 -> number의 순서가 고정되어 있기 때문!
 * !주의! 구역의 끝 위치는 다음 구역으로 넘어갈 때 꼭 1씩 증가시켜야 함
 */

string solution(string number, int k) {
    string answer = "";
    int l = number.length(); //주어진 number의 길이
    vector<int> num(l, 0); //큰 수 계산하기 편하게 int형으로 미리 저장하기 위한 배열
    for (int i = 0; i < l; i++)
        num[i] = number[i] - '0';

    //연산
    int cur_idx = -1; //현재 구역에서 큰 값의 위치
    int end = k; //현재 검사하는 구역의 끝 위치
    for (int i = 0; i < l - k; i++) {
        int start = cur_idx + 1;
        int cur_max = 0; //구역에서 가장 큰 값
        for (int j = start; j <= end; j++) {
            if (cur_max < num[j]) {
                cur_max = num[j];
                cur_idx = j;
            }
        }
        answer += to_string(cur_max);
        end++; //다음 구역의 끝 위치
    }

    return answer;
}

int main() {
    string number = "1924";
    int k = 2;

    //연산 &출력
    cout << solution(number, k);

    return 0;
}