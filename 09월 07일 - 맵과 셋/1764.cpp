#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main() {
    int n, m;
    set<string> never_heard, result;
    string input;

    //입력
    cin >> n >> m;

    //듣도 못한 사람
    while (n--) {
        cin >> input;
        never_heard.insert(input);
    }

    //보도 못한 사람
    while (m--) {
        cin >> input;
        //듣도 못한 사람 명단에도 있다면 듣도 보도 못한 사람
        if (never_heard.find(input) != never_heard.end())
            result.insert(input);
    }

    //출력
    cout << result.size() << '\n';
    for (auto iter = result.begin(); iter != result.end(); iter++)
        cout << *iter << '\n';
}
