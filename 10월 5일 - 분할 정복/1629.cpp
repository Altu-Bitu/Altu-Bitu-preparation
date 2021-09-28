#include <iostream>

using namespace std;
typedef long long ll;

ll divide(int a, int b, int c) {
    //Conquer : B가 1인가?
    if (b == 1)
        return a % c;

    //Divide : 제곱 수 나누기
    if (b % 2 == 0) { //b가 짝수일 때
        ll sub_problem = divide(a, b / 2, c);
        return (sub_problem * sub_problem) % c;
    }
    //b가 홀수일 때
    return (a * divide(a, b - 1, c)) % c;
}

int main() {
    int a, b, c;

    //입력
    cin >> a >> b >> c;

    //연산 & 출력
    cout << divide(a, b, c);
}