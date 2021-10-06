#include <iostream>
#include <vector>

using namespace std;

//cnt명이 건널 때, 건너 뛰어야 하는 디딤돌 칸 수의 최댓값
int jumpDist(vector<int> &stones, int cnt) {
    int max_dist = 0, cur_dist = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] >= cnt) { //밟을 수 있음
            max_dist = max(max_dist, cur_dist);
            cur_dist = 0;
        } else if (stones[i] < cnt) //밟을 수 없음
            cur_dist++;
    }
    max_dist = max(max_dist, cur_dist); //개울의 오른쪽 건너편까지 이동
    return max_dist;
}

int upperSearch(vector<int> &stones, int left, int right, int target) {
    int ans = 0;
    while (left <= right) {
        //mid만큼의 친구들이 건널 때, 건너 뛰어야 하는 디딤돌 칸 수의 최댓값은 몇칸인가?
        int mid = (left + right) / 2;
        int jump = jumpDist(stones, mid);

        if (jump < target) {
            ans = mid;
            left = mid + 1;
        } else if (jump >= target)
            right = mid - 1;
    }
    return ans;
}

/**
 * 징검다리를 건널 수 있는 니니즈 친구들의 최댓값
 * -> 니니즈 친구들 n명이 징검다리를 건널 때, 건너 뛰어야 하는 디딤돌 칸 수의 최댓값이 k보다 작은가?
 *
 * left : 배열의 원소가 1이상이기 때문에 최소한 1명은 건널 수 있음
 * right : 아무리 많이 건너도 배열 원소의 최댓값보다 많은 인원이 건널 수는 없음
 */
int solution(vector<int> stones, int k) {
    int right = 0; //배열 원소의 최댓값
    for (int i = 0; i < stones.size(); i++)
        right = max(right, stones[i]);

    return upperSearch(stones, 1, right, k);
}

int main() {
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;
    cout << solution(stones, k);
}