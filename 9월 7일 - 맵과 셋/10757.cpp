#include <iostream>
#include <stack>

using namespace std;

/**
 * 1. 한 자릿수씩 더해서 스택(혹은 배열)에 저장
 * 2. 한 자릿수씩 더할 때, 값이 10을 넘어가는 경우 고려
 * 3. A와 B의 길이가 같지만, 둘의 합의 길이는 다른 경우 고려
 * 4. A와 B의 길이가 다른 경우 고려
 *
 * 본 풀이에서 더한 결과값을 스택에 넣는 이유는 일의자릿수부터 더하기 때문
 * 배열을 사용할 경우 마지막 인덱스부터 출력하면 됨
 */

//한 자릿수씩 더해서 값 리턴하는 함수
int digitPlus(string &a, string &b, int p1, int p2, bool carry) {
    int num = 0;
    if (p1 >= 0) //p1 인덱스가 0 이상이라면 -> a에 남은 수가 존재한다면
        num += (a[p1] - '0');
    if (p2 >= 0) //p2 인덱스가 0 이상이라면 -> b에 남은 수가 존재한다면
        num += (b[p2] - '0');
    if (carry) //전 자릿수에서 올림되었다면
        return num + 1;
    return num;
}

//A + B 함수, 일의 자릿수부터 더함
stack<int> calcPlus(string &a, string &b) {
    stack<int> st;
    int p1 = a.length() - 1; //a의 일의 자릿수 인덱스
    int p2 = b.length() - 1; //b의 일의 자릿수 인덱스
    int num = 0;

    while (p1 >= 0 || p2 >= 0) { //자릿수 더하기
        if (num >= 10) //그 전 자릿수 더하기 값이 10을 넘었다면 올림변수인 carry를 true로 호출
            num = digitPlus(a, b, p1--, p2--, true);
        else
            num = digitPlus(a, b, p1--, p2--, false);
        st.push(num % 10); //올림값 제외한 한 자릿수만 스택에 저장
    }
    if (num >= 10) //마지막 올림 확인
        st.push(1);

    return st;
}

int main() {
    string a, b; //입력 수가 매우 크므로 string 으로 입력
    stack<int> st; //더한 결과값 저장할 스택

    //입력
    cin >> a >> b;

    //연산
    st = calcPlus(a, b);

    //출력
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << '\n';

    return 0;
}