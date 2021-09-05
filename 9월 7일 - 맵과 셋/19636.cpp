#include <iostream>

using namespace std;

typedef pair<int, int> ci;

/**
 * 단순 구현 문제
 * 체중(W): 일일 에너지 섭취량(I) - 일일 에너지 소비량(E) (일일 기초 대사량(B) + 일일 활동 대사량(A))
 * if |일일 에너지 섭취량(I) - 일일 에너지 소비량(E)| > 기초 대사량 변화 역치(T)
 * -> 일일 기초 대사량(B) += [(일일 에너지 섭취량(I) - 일일 에너지 소비량(E)) / 2]
 * -> !주의! 이때 일일 기초 대사량에서 더해지는 값이 Floor 함수 적용이므로 음수일 때 값처리 주의해야 함
 */

ci diet(int D, int W, int I, int A, int B, int T) {
    while (D--) {
        int E = B + A; //일일 에너지 소비량
        W += (I - E); //체중변화

        if (T && abs(I - E) > T) { //일일 기초 대사량 고려하는 경우
            if ((I - E) / 2 < 0) B += (I - E - 1) / 2; //c++에서 음수의 소수점은 그냥 버려지므로 내림함수를 만족시키기 위해선 -1을 하고 나누어줘야함
            else B += (I - E) / 2;
        }

        if (W <= 0 || B <= 0) return ci(0, 0); //체중이나 기초대사량이 0 이하라면 출력 후 바로 리턴
    }
    return ci(W, B);
}

int main() {
    int W0, I0, T, D, I, A;

    //입력
    cin >> W0 >> I0 >> T;
    cin >> D >> I >> A;

    //일일 기초 대사량의 변화를 고려하지 않는 경우
    ci result = diet(D, W0, I, A, I0, 0);
    if (!result.first || !result.second) { //최종 체중이나 일일 기초대사량 값이 0 이하면 Danger Diet
        cout << "Danger Diet\n";
    } else {
        cout << result.first << ' ' << result.second << '\n';
    }
    //일일 기초 대사량의 변화를 고려하는 경우
    result = diet(D, W0, I, A, I0, T);
    if (!result.first || !result.second) { //최종 체중이나 일일 기초대사량 값이 0 이하면 Danger Diet
        cout << "Danger Diet\n";
    } else {
        string ans = "NO";
        if (I0 - result.second > 0) //다이어트 후 일일 기초대사량을 유지하며 원래의 일일 에너지 섭취량과 일일 활동 대사량(0)으로 돌아갔을 때 체중 증가
            ans = "YOYO";
        cout << result.first << ' ' << result.second << ' ' << ans << '\n';
    }

    return 0;
}