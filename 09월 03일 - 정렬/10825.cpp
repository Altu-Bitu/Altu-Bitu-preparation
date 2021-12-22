#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//학생의 정보를 담은 구조체
struct info {
    string name;
    int korean, english, math;
};

//먼저 가독성 면에서 좋지 않은 코드를 먼저 보여주고 리팩토링 하려구요(튜터용)
//비교함수(bad)
bool cmp(const info &i1, const info &i2) {
    if (i1.korean == i2.korean) { //국어 점수가 같다면
        if (i1.english == i2.english) { //영어 점수가 같다면
            if (i1.math == i2.math) //수학 점수가 같다면
                return i1.name < i2.name;
            return i1.math > i2.math;
        }
        return i1.english < i2.english;
    }
    return i1.korean > i2.korean;
}

//비교함수(good)
bool cmpAdv(const info &i1, const info &i2) {
    if (i1.korean != i2.korean) //국어 점수가 다르다면 감소하는 순서
        return i1.korean > i2.korean;
    if (i1.english != i2.english) //영어 점수가 다르다면 증가하는 순서
        return i1.english < i2.english;
    if (i1.math != i2.math) //수학 점수가 다르다면 감소하는 순서
        return i1.math > i2.math;
    return i1.name < i2.name; //이름이 사전 순으로 증가하는 순서
}

int main() {
    int n;
    vector<info> student;

    //입력
    cin >> n;
    student.assign(n, {});
    for (int i = 0; i < n; i++)
        cin >> student[i].name >> student[i].korean >> student[i].english >> student[i].math;

    //연산
    sort(student.begin(), student.end(), cmp);

    //출력
    for (int i = 0; i < n; i++)
        cout << student[i].name << '\n';
}