#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 4000; //양수의 최댓값

int calcMode(vector<int> &frequency) {
    int max = 0;  //최빈값의 빈도수
    for (int i = 0; i <= 8000; i++) { //최빈값의 빈도수 구하기
        if (frequency[i] > max)
            max = frequency[i];
    }
    //두 번째로 작은 최빈값 구하기
    int cnt = 0;  //최빈값 개수
    int mode = 0; //최빈값
    for (int i = 0; i <= 8000; i++) {
        if (frequency[i] == max) {
            mode = i - SIZE; //SIZE를 더한 값으로 인덱스에 저장했었으므로 실제 값은 SIZE를 빼주어야 함
            cnt++;
            if (cnt == 2) //두 번째로 작은 최빈값
                break;
        }
    }

    return mode;
}

/**
 * 1. 산술평균 계산 시 실수 자료형으로 맞춰준 후 반올림하는거 주의
 * 2. n은 홀수이므로 중앙값은 항상 (n / 2)번째 인덱스
 * 3. 최빈값은 동일한 빈도수 내에서 두 번째로 '작은' 값임
 * 4. 최빈값이 유일하게 하나만 있는 경우
 */

int main() {
    int n; //n은 홀수

    //입력
    cin >> n;

    vector<int> num(n);
    vector<int> frequency(SIZE * 2 + 1, 0); //인덱스는 입력 수 + 4000의 값. 따라서 0 ~ 8000. 각 인덱스에 해당 수가 얼마나 나왔는지 저장

    double sum = 0;             //평균 구하기 위한 합 변수
    int max = (-1) * SIZE - 1;  //가장 큰 값
    int min = SIZE + 1;         //가장 작은 값
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        sum += (double) num[i];
        frequency[num[i] + SIZE]++;
        if (max < num[i]) max = num[i];
        if (min > num[i]) min = num[i];
    }

    //연산
    sort(num.begin(), num.end());

    //출력
    cout << round(sum / n) << '\n';    //산술평균
    cout << num[n / 2] << '\n';        //중앙값
    cout << calcMode(frequency) << '\n';   //최빈값
    cout << max - min << '\n';         //범위

    return 0;
}