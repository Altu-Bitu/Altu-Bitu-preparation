#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<int, int> liquid(int left, int right) {
    pair<int, int> ans;
    int min_diff = 2 * 1e9 + 1;

    //left는 항상 right의 왼쪽에 있어야 함
    while (left < right) {
        int mix = arr[left] + arr[right]; //두 용액을 혼합
        if (mix == 0)  //그 값이 0이라면 이보다 더 0에 가까워질 수는 없기 때문에 바로 리턴
            return make_pair(arr[left], arr[right]);
        if (abs(mix) < min_diff) { //0에 가까운 값을 갱신할 수 있는지 확인
            min_diff = abs(mix);
            ans = make_pair(arr[left], arr[right]);
        }
        if (mix > 0) //0보다 크면 더 작은 값을 만들어야 함
            right--;
        if (mix < 0) //0보다 작으면 더 큰 값을 만들어야 함
            left++;
    }
    return ans;
}

int main() {
    int n;

    //입력
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    sort(arr.begin(), arr.end());
    pair<int, int> p = liquid(0, n - 1);

    //출력
    cout << p.first << ' ' << p.second;
}