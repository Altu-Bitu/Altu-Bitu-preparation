#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 10001; //큐의 최대 크기

int front_pointer = 0, rear_pointer = 0;
vector<int> queue_vec(SIZE);

//empty
bool empty() {
    return front_pointer == rear_pointer;
}

//full
bool full() {
    return (rear_pointer + 1) % SIZE == front_pointer;
}

//push
void push(int num) {
    rear_pointer = (rear_pointer + 1) % SIZE;
    queue_vec[rear_pointer] = num;
}

//pop
int pop() {
    front_pointer = (front_pointer + 1) % SIZE;
    return queue_vec[front_pointer];
}

//size
int size() {
    int tmp = (rear_pointer - front_pointer);
    if (tmp < 0) //rear = 1, front = 3일 때
        tmp += SIZE;
    return tmp;
}

//front
int front() {
    int tmp = (front_pointer + 1) % SIZE;
    return queue_vec[tmp];
}

//back
int back() {
    return queue_vec[rear_pointer];
}

/**
 * 스택과 유사합니다!
 * 스택은 최대 크기가 10000이었는데 큐는 거기서 1을 더한 이유를 추가로 설명하려고 해요
 */
int main() {
    int n, num;
    string cmd;

    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> num;
            if (!full()) //큐 라이브러리 사용시엔 필요없음
                push(num);
        } else if (cmd == "pop") {
            if (empty()) //큐에서 값을 구할 땐 반드시 empty 체크를 해야함 (런타임 에러 방지)
                cout << -1 << '\n';
            else
                cout << pop() << '\n';
        } else if (cmd == "size")
            cout << size() << '\n';
        else if (cmd == "empty")
            cout << empty() << '\n';
        else if (cmd == "front") {
            if (empty()) //큐에서 값을 구할 땐 반드시 empty 체크를 해야함 (런타임 에러 방지)
                cout << -1 << '\n';
            else
                cout << front() << '\n';
        } else if (cmd == "back") {
            if (empty()) //큐에서 값을 구할 땐 반드시 empty 체크를 해야함 (런타임 에러 방지)
                cout << -1 << '\n';
            else
                cout << back() << '\n';
        }
    }
}