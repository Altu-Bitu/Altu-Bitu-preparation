#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    string input;
    map<string, int> name;
    map<int, string> number;

    //입력
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        name[input] = i; //key : 이름, value : 번호
        number[i] = input; //key : 번호, value : 이름
    }

    //출력
    for (int i = 0; i < m; i++) {
        cin >> input;
        if (isdigit(input[0])) //입력이 숫자라면
            cout << number[stoi(input)] << '\n'; //stoi 설명할거예요!(튜터용)
        else //입력이 문자라면
            cout << name[input] << '\n';
    }
}