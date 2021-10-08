#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

/**
 * (튜터용)
 * 앞에서 구현한 binarySearch 함수를 그대로 들고와서 수정하면서 다른 부분을 설명하려구요!
 */
//lower bound
int lowerBound(int left, int right, int target) {
    while (left <= right) { //left 포인터와 right 포인터의 위치가 반전되면 break
        int mid = (left + right) / 2; //중간값
        //중간값이 target보다 크다면 target은 왼쪽에 있음
        //중간값이 target과 같다면 왼쪽에 target과 같은 값이 더 있을 수 있음
        if (arr[mid] >= target)
            right = mid - 1;
        if (arr[mid] < target) //중간값이 target보다 작다면 target은 오른쪽에 있음
            left = mid + 1;
    }
    /**
     * right + 1을 리턴하는 이유
     * right가 움직일 때는 arr[mid]가 target 이상일 때
     * target 이상이면서 인덱스가 가장 작은 mid 값은 lower bound!
     * right는 mid - 1이므로 right + 1은 lower bound
     */
    return right + 1; //처음으로 target 이상인 수가 등장하는 위치
}

//upper bound
int upperBound(int left, int right, int target) {
    while (left <= right) { //left 포인터와 right 포인터의 위치가 반전되면 break
        int mid = (left + right) / 2; //중간값
        if (arr[mid] > target)  //중간값이 target보다 크다면 target은 왼쪽에 있음
            right = mid - 1;
        //중간값이 target보다 작다면 target은 오른쪽에 있음
        //중간값이 target과 같다면 오른쪽에 target과 같은 값이 더 있을 수 있음
        if (arr[mid] <= target)
            left = mid + 1;
    }
    /**
     * right + 1을 리턴하는 이유
     * break 직전 left와 right는 같은 곳을 가리킴
     * 이 상태에서 right(mid)가 가리키는 값은 target 이하기 때문에 left 포인터가 이동하고 break
     * 이 때의 left 값은 target을 처음으로 초과하는 upper bound이며 직전에 left와 right의 위치가 같았으므로 right + 1 == left
     */
    return right + 1; //처음으로 target을 초과하는 수가 등장하는 위치
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, input;

    //입력
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    sort(arr.begin(), arr.end()); //이분 탐색을 하기 위해선 반드시 정렬을 해야함

    cin >> m;
    while (m--) {
        //입력
        cin >> input;

        //연산 & 출력
        cout << upperBound(0, n - 1, input) - lowerBound(0, n - 1, input) << ' ';
        //cout << upper_bound(arr.begin(), arr.end(), input) - lower_bound(arr.begin(), arr.end(), input) << ' ';
    }
}
