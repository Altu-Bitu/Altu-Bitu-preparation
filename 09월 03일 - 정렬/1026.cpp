#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//굳이 함수화 안해도 될 것 같긴 했는데,,,그냥 메인이 짧으면 좋으니까 했어요(튜터용)
//함수 S의 계산
int calcS(int n, vector<int> a, vector<int> b) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += (a[i] * b[i]);
    return s;
}

/**
 * 문제에서 B를 재배열하지 말라곤 했지만, 해야하는 문제
 * 각 배열에서 가장 큰 값과 가장 작은 값을 곱해야 최솟값이 나옴!
 */
int main() {
    int n;
    vector<int> a, b;

    //입력
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    //연산
    sort(a.begin(), a.end()); //오름차순 정렬
    sort(b.begin(), b.end(), greater<>()); //내림차순 정렬
    int result = calcS(n, a, b);

    //출력
    cout << result;
}