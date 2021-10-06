#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    int n, m, power;
    string name;

    //입력
    cin >> n >> m;
    while (n--) {
        cin >> name >> power;
        if (title[power].empty())
            title[power] = name;
    }

    //출력
    while (m--) {
        cin >> power;
        cout << title.lower_bound(power)->second << '\n';
    }
}