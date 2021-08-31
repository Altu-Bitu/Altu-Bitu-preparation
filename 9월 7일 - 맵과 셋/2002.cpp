#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    string input;
    map<string, int> m;

    //입력
    cin >> n;
    for (int i = 0; i < n; i++) { //들어갈 때의 차들의 순서
        cin >> input;
        m[input] = i;
    }

    vector<int> seq;
    for (int i = 0; i < n; i++) { //나올 때의 차들의 순서
        cin >> input;
        seq.push_back(m[input]);
    }
    //디버깅 예시용
//    for (int i = 0; i < n; i++)
//        cout << seq[i] << ' ';
//    cout << '\n';

    int result = 0;
    for (int i = 0; i < n; i++) { //i<n-1이 정확하긴 하겠지만, 헷갈려 하실까봐 일단 저렇게 써놨어요 괜찮을까요?(튜터용)
        //디버깅 하고 나서 함수로 뺄수도...? 그때 시간봐서 할지말지 할 것 같아요(튜터용)
        for (int j = i + 1; j < n; j++) { //i 번째로 나온 차보다 늦게 나온 모든 차들
            if (seq[i] > seq[j]) { //i번 차보다 인덱스가 작은 j번 차가 하나라도 있다면
                //cout<<seq[i]<<' '<<seq[j]<<'\n'; //디버깅 예시용
                result++;
                break; //처음엔 break문 안쓰고 답 안나오는거 보여주고 디버깅하는 과정 보여주려구요(튜터용)
            }
        }
    }

    //출력
    cout << result;
}