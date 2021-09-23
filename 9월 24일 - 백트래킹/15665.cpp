#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 7; //배열 크기
const int RANGE = 10000; //주어지는 수 범위

int n, m, leng; //leng: 서로 다른 수의 개수
int num[SIZE];
int ans[SIZE];
int check[RANGE];

void backtracking(int cnt) {
    if (cnt == m) { //길이 m이라면 (기저조건)
        for (int i = 0; i < cnt; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < leng; i++) {
        if (check[num[i]] >= 0) { //해당 수 사용 가능하다면
            check[num[i]]--;
            ans[cnt] = num[i];
            backtracking(cnt + 1);
            check[num[i]]++;
        }
    }
}

/**
 * [백트래킹 풀이] (180ms)
 * 조건: 같은 수 여러 번 사용 가능, 수열은 중복되면 안됨, 사전 순으로 출력
 * '같은 수 여러 번'
 * -> 그래도 구하려는 수열 길이가 m이므로 각 수는 '최대 m번' 까지밖에 사용 못함.
 * -> check 배열을 미리 m으로 초기화(사용할 수 있는 횟수)하고 사용할 때마다 감소시키자!
 * -> check 배열이 0 미만이면 사용 불가 (가지치기)
 * '수열 중복되면 안됨' 조건도 위 과정에서 만족
 * '사전 순으로 출력' (N과 M(1)과 동일)
 */

int main() {
    int a;

    //입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (check[a] == 0) //check가 초기화 되기 전. 즉, 처음 나온 수라면
            num[leng++] = a;
        check[a] = m; //check 초기화 (a를 m만큼 사용할 수 있다는 뜻)
    }

    //연산
    sort(num, num + leng);

    //연산 + 출력
    backtracking(0);

    return 0;
}