#include <iostream>

using namespace std;

//재귀함수로 구현한 유클리드 호제법
int gcdRecursion(int a, int b) {
    if (b == 0) //b가 0이면 a가 최대공약수
        return a;
    //a%b구한 후 b와 자리 바꾸어서 호출
    return gcdRecursion(b, a % b);
}

int main() {
    string s;
    int n, m;

    //입력
    cin >> s;

    //연산(입력으로부터 n, m 추출하기)
    string temp_s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ':') {
            n = stoi(temp_s); //: 이전의 문자를 숫자로 변경
            temp_s = "";
            continue;
        }
        temp_s += s[i];
    }
    m = stoi(temp_s); //: 이후 문자를 숫자로 변경

    //최대공약수 구하기
    int g = gcdRecursion(max(n, m), min(n, m));

    //출력
    cout << n / g << ':' << m / g << '\n';

    return 0;
} 