#include <iostream>
#include <vector>

using namespace std;

/**
 * 1. 한 자릿수씩 더해서 배열에 저장
 * 2. A와 B의 길이가 같지만, 둘의 합의 길이는 다른 경우 고려
 * 3. A와 B의 길이가 다른 경우 고려
 *
 * 다양한 풀이가 있지만, 본 풀이는 3을 고려해 일의 자릿수 값부터 벡터에 저장
 */

//한 자릿수씩 더하는 함수, 일의 자릿수부터 시작
vector<int> calcPlus(vector<int> &a, vector<int> &b, int l) {
    vector<int> result;
    int plus = 0; //현재 자릿수가 10보다 커서 다음 자릿수로 넘어간 수 저장, 항상 0 또는 1의 값을 지님
    for (int i = 0; i < l; i++) {
        int num = plus + a[i] + b[i]; //각 자릿수의 값 + 전 자릿수에서 넘어온 수 더함
        plus = num / 10; //다음 자릿수로 넘어가서 더해지는 수
        result.push_back(num % 10); //현재 자릿수 최종 값
    }
    if (plus) //마지막 제일 큰 자릿수가 10보다 커서 다음 자릿수까지 넘어갔는지 검사
        result.push_back(plus);
    return result;
}

//string 으로 받은 입력 수를 벡터에 일의 자릿수 값부터 저장
vector<int> stringToVec(string str, int l) {
    vector<int> arr(l, 0); //길이가 l보다 작다면 남은 값엔 0이 들어가도록 초기화
    for (int i = str.length() - 1; i >= 0; i--) //일의 자릿수 값부터
        arr[(str.length()-1) - i] = str[i] - '0'; //0번 인덱스부터 해당 자릿수 값을 저장
    return arr;
}

int main() {
    string str_a, str_b; //입력 수의 길이가 매우 기므로 string 으로 입력
    vector<int> a, b, result; //각 A, B의 각 자릿수에 대한 값 저장, 더한 결과 저장하는 result 배열

    //입력
    cin >> str_a >> str_b;

    //연산
    int l = max(str_a.length(), str_b.length()); //둘 중 더 긴 길이 저장 -> 더 긴 길이까지 더해야 하므로
    //string으로 받은 입력을 각 자릿수 값이 저장되는 벡터로 변환
    //여기 이렇게 함수화할지 아니면 그냥 메인에서 처리할지 고민중인데 뭐가 좋을까요,,?(튜터용)
    a = stringToVec(str_a, l);
    b = stringToVec(str_b, l);
    //한 자릿수씩 더하는 함수 호출해서 결과값 저장
    result = calcPlus(a, b, l);

    //출력
    for (int i = result.size() - 1; i >= 0; i--) //일의 자릿수부터 저장되었으므로 마지막 인덱스 값부터 출력
        cout << result[i];
    cout << '\n';

    return 0;
}