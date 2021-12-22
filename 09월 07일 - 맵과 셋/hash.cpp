#include <iostream>
#include <vector>

using namespace std;
const int MAX_SIZE = 3;

//버킷
vector<vector<pair<string, int>>> bucket;

//해시 함수
int hashFunc(string str) {
    int key = 0;
    for (int i = 0; i < str.size(); i++)
        key += (str[i] - 'a') * i;
    return key % MAX_SIZE;
}

//버킷의 상태를 출력
void printHash() {
    for (int i = 0; i < MAX_SIZE; i++) { //i번째 버킷
        cout << "[ " << i << " ] -> ";
        for (int j = 0; j < bucket[i].size(); j++) //i번째 버킷에 있는 모든 데이터 출력
            cout << "( " << bucket[i][j].first << ' ' << bucket[i][j].second << " ) ";
        cout << '\n';
    }
}

//학생 이름으로 점수 찾기
int findScore(string name) {
    int key = hashFunc(name); //key 값
    for (int i = 0; i < bucket[key].size(); i++) { //해당하는 버킷에서 일치하는 데이터 찾기
        if (bucket[key][i].first == name)
            return bucket[key][i].second;
    }
    return -1; //일치하는 데이터가 없음
}

int main() {
    //입력
    vector<pair<string, int>> student;
    student.emplace_back("lee", 42);
    student.emplace_back("kim", 100);
    student.emplace_back("lim", 75);
    student.emplace_back("park", 88);

    //연산
    bucket.assign(MAX_SIZE, vector<pair<string, int>>(0));
    for (int i = 0; i < student.size(); i++) {
        int key = hashFunc(student[i].first); //해시 함수를 통해 int형의 key값으로 변환
        bucket[key].push_back(student[i]);

        //인라인 단축키 써서(컨트롤+알트+N) 합친 것도 보여주려고 합니다.(튜터용)
        //bucket[hashFunc(student[i].first)].push_back(student[i]);
    }
    printHash();

    string target = "lim";
    int score = findScore(target);

    //출력
    if (score == -1)
        cout << "No Such Data\n";
    else
        cout << "Score of " << target << " : " << score << '\n';
}