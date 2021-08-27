#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, input;
    set<int> s;

    //입력
    //인덱스를 쓸 필요가 없고, n을 다시 쓰지 않아서 for문이 아니라 while문을 쓴다고 설명할 생각입니다(튜터용)
    cin >> n;
    while (n--) {
        cin >> input;
        s.insert(input);
    }

    //출력
    for (auto iter = s.begin(); iter != s.end(); iter++)
        cout << *iter << ' ';
}
