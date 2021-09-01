#include <iostream>
#include <vector>

using namespace std;

vector<int> heap_vec;

//empty
bool empty() {
    return heap_vec.size() == 1;
}

//push
void push(int num) {
    int idx = heap_vec.size(); //힙의 가장 마지막 데이터의 인덱스
    heap_vec.push_back(num); //새로운 데이터를 맨 뒤에 삽입

    //root = 1에 도달하거나, 더이상 상위노드보다 값이 크지 않다면 반복문 탈출
    while (idx != 1 && heap_vec[idx] > heap_vec[idx / 2]) {
        swap(heap_vec[idx], heap_vec[idx / 2]); //하위노드와 상위노드의 값을 바꿈
        idx /= 2; //상위노드로 이동
    }
}

//pop
int pop() {
    int item = heap_vec[1]; //root 데이터
    swap(heap_vec[1], heap_vec[heap_vec.size() - 1]); //힙의 맨 마지막 값과 바꿈
    heap_vec.pop_back(); //데이터 제거

    //leaf node(=하위노드가 없는 노드)에 도달하거나, 본인보다 큰 하위노드가 없다면 반복문 탈출
    int parent = 1, child = 2;
    while (child < heap_vec.size()) {
        //만약 오른쪽 하위노드가 존재하면 왼쪽 하위노드와 값 비교
        if (child + 1 < heap_vec.size() && heap_vec[child] < heap_vec[child + 1])
            child++;
        if (heap_vec[parent] >= heap_vec[child]) //본인보다 큰 하위노드가 없음
            break;
        swap(heap_vec[parent], heap_vec[child]); //상위노드와 하위노드의 값을 바꿈
        parent = child; //상위노드 값 갱신
        child = parent * 2; //하위노드 값 갱신
    }
    return item;
}

//직접 구현한 뒤 라이브러리로 리팩토링 할거예요!(튜터용)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    heap_vec.push_back(0); //인덱스가 1부터 시작하도록

    cin >> n;
    while (n--) {
        cin >> x;
        if (x == 0) {
            if (empty()) //런타임 에러 방지
                cout << 0 << '\n';
            else
                cout << pop() << '\n';
        } else
            push(x);
    }
}