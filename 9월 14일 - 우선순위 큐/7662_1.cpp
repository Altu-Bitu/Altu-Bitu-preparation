#include <iostream>
#include <set>

using namespace std;

/**
 * set 풀이
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k, n;
    char cmd;

    cin >> t;
    while (t--) {
        multiset<int> q; //중복 저장
        cin >> k;
        while (k--) {
            //입력
            cin >> cmd >> n;

            //연산
            if (cmd == 'I') //I 연산
                q.insert(n);
            else if (!q.empty()) { //D 연산이면서 Q가 비어있지 않을 때
                if (n == 1) //최댓값 삭제
                    q.erase(--q.end());
                else //최솟값 삭제
                    q.erase(q.begin());
            }
        }

        //출력
        if (q.empty())
            cout << "EMPTY\n";
        else
            cout << *(--q.end()) << ' ' << *q.begin() << '\n';
    }
}