#include <iostream>
#include <stack>
#include <map>

using namespace std;

//괄호의 짝을 저장할 맵
map<char, char> bracket;

//균형을 이루었는지 판단하는 함수
bool isBalanced(string input) {
    stack<char> s;

    for (int i = 0; i < input.size(); i++) {
        switch (input[i]) {
            case '(': case '[': //왼쪽 괄호
                s.push(input[i]);
                break;
            case ')': case ']': //오른쪽 괄호
                if (s.empty() || s.top() != bracket[input[i]]) //case 1, 2
                    return false;
                s.pop();
                break;
        }
    }
    //문제의 예제 입력은 return true 해도 제대로 나오는데, 반례가 있잖아요..! 그래서 처음엔 그냥 바로 true 리턴하고 안되는거 보여주고 추가 설명하려구요 (튜터용)
    //return true;
    return s.empty(); //case 3 (예제 입력으론 알 수 없는 반례)
}

int main() {
    string input;
    bracket[')'] = '(';
    bracket[']'] = '[';

    while (true) {
        //입력
        getline(cin, input); //띄어쓰기 포함 입력 받기
        if (input == ".")
            break;

        //연산 & 출력
        if (isBalanced(input))
            cout << "yes\n";
        else
            cout << "no\n";
        /**
         * (튜터용)
         * 삼항연산자에 대한 논의가 많지만,,, 그래도 출력부분은 써도 괜찮지 않을까 싶어서 얘도 소개할까 싶어요
         * 그래도 가능하면 지양하고, 하더라도 출력부에만 사용하도록 설명할게요...!
         */
        //cout << (isBalanced(input) ? "yes" : "no") << '\n';
    }
}