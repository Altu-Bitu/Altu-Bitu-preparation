#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 10000; //스택의 최대 크기

int top_pointer = -1;
vector<int> stack_vec(SIZE);

//empty
bool empty() {
    return top_pointer == -1;
}

//full
bool full() {
    return top_pointer == SIZE - 1;
}

//push
void push(int num) {
    stack_vec[++top_pointer] = num;
}

//pop
int pop() {
    return stack_vec[top_pointer--];
}

//size
int size() {
    return top_pointer + 1;
}

//top
int top() {
    return stack_vec[top_pointer];
}

/**
 * (튜터용)
 * 직접 구현한 함수 이름은 일부러 실제 라이브러리 함수랑 똑같이 맞췄어요.
 * full 함수는 사실 필요없지만 그래도 배열로 구현하는 건데 빼면 안될 것 같아서 넣었습니다.
 * full 함수가 필요없는 이유, 그럼에도 불구하고 구현하는 이유 전부 설명할 생각이에요!
 * 원래 full, empty 함수를 push, pop, top 함수에 넣으려고 했는데, 실제 라이브러리랑 최대한 유사하게 하려고 메인에서 각각 호출하는걸로 처리했습니다!
 */
int main() {
    int n, num;
    string cmd;

    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> num;
            if (!full()) //스택 라이브러리 사용시엔 필요없음
                push(num);
            continue;
        }
        if (cmd == "pop") {
            if (empty()) //런타임 에러 방지
                cout << -1 << '\n';
            else
                cout << pop() << '\n';
            continue;
        }
        if (cmd == "size") {
            cout << size() << '\n';
            continue;
        }
        if (cmd == "empty") {
            cout << empty() << '\n';
            continue;
        }
        if (cmd == "top") {
            if (empty()) //런타임 에러 방지
                cout << -1 << '\n';
            else
                cout << top() << '\n';
            continue;
        }
    }
}