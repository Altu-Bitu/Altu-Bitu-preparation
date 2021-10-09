#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int MAX = 100000;

vector<int> arr;

int findLen(int n, int k) {
    vector<int> cnt(MAX + 1, 0); //각 원소 등장 횟수

    int ans = 0, left = 0, right = 0;
    set<int> s; //k번보다 많이 등장한 원소
    cnt[arr[0]]++; //초기값

    //left는 항상 right의 왼쪽 또는 같은 위치에 있어야 함
    while (left <= right && right < n) {
        if (s.empty()) { //k번 보다 많이 등장한 원소가 없다면 범위 늘리기
            ans = max(ans, (right - left) + 1);
            right++;
            if (right == n)
                break;

            cnt[arr[right]]++;
            if (cnt[arr[right]] > k) //k번 초과
                s.insert(arr[right]);
        } else { //k번 보다 많이 등장한 원소가 있다면 범위 줄이기
            cnt[arr[left]]--;
            if (cnt[arr[left]] == k) //원래 등장 횟수가 k번을 초과했던 원소
                s.erase(arr[left]);
            left++;
        }
    }
    return ans;
}

/**
 * 1. 최장 연속 부분 수열의 '길이'를 구해야 함 -> 구간 내의 모든 원소를 고려하기 때문에 한쪽에서 시작하는 투 포인터
 * 2. 각 원소의 최댓값이 100,000이기 때문에 배열로 등장 횟수 체크할 수 있음
 * 3. 매번 배열을 돌며 k번 이상 등장한 원소 찾기? -> 비효율적! k번 이상 등장한 원소를 set에 넣자
 */
int main() {
    int n, k;

    //입력
    cin >> n >> k;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산 & 출력
    cout << findLen(n, k);
}