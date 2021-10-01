#include <iostream>
#include <vector>

using namespace std;

//에라토스테네스의 체로 n 이하의 모든 소수 구하기
vector<bool> isPrime(int n) {
    vector<bool> is_prime(n + 1, true); //소수 여부 저장

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) { //i가 소수라면
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false; //i의 배수 제거
        }
    }
    return is_prime;
}

//n 이하의 모든 소수
vector<int> primeList(vector<bool> &is_prime) {
    vector<int> prime_list;

    for (int i = 2; i <= is_prime.size(); i++) {
        if (is_prime[i])
            prime_list.push_back(i);
    }
    return prime_list;
}

//투 포인터로 연속된 소수의 합이 n인 구간의 개수 구하기
int findSum(vector<int> &prime_list, int target) {
    int ans = 0;
    int size = prime_list.size(), left = 0, right = 0;
    int sum = prime_list[left]; //초기 구간

    //left는 항상 right의 왼쪽 또는 같은 위치에 있어야 함
    while (left <= right && right < size) {
        if (sum == target) { //구간의 합이 target과 같으면
            ans++; left++; right++; //모든 포인터 이동
            if (right == size) //런타임 에러 방지
                break;
            sum -= prime_list[left - 1]; //이번 구간에 제외되는 값
            sum += prime_list[right]; //이번 구간에 추가되는 값
        } else if (sum > target) { //구간의 합이 target보다 크면
            left++; //합을 작게하기 위해 left 이동
            sum -= prime_list[left - 1];
        } else if (sum < target) { //구간의 합이 target보다 작다면
            right++; //합을 크게하기 위해 right 이동
            if (right == size)
                break;
            sum += prime_list[right];
        }
        /**
         * (튜터용)
         * 먼저 ppt 기반으로 저렇게 짠 다음에 이걸로 리팩토링할까봐여,,,
         * 어차피 연산에 큰 차이도 없고 left==right인 경우였다면 그 뒤에 있는 숫자는 target보다 큰거니까 어차피 size도 넘었을거고,,,아니었어도 더 가망없었을 거고 해서요
         * 한 4ms 정도 더 걸리네욥
         */
//        if (sum >= target) { //구간의 합이 target보다 크거나 같다면
//            if (sum == target) //같다면
//                ans++;
//            left++; //합을 작게하기 위해 left 이동
//            sum -= prime_list[left - 1];
//        } else if (sum < target) { //구간의 합이 target보다 작다면
//            right++; //합을 크게하기 위해 right 이동
//            if (right == size)
//                break;
//            sum += prime_list[right];
//        }
    }
    return ans;
}

int main() {
    int n;

    //입력
    cin >> n;

    //연산
    vector<bool> is_prime = isPrime(n);
    vector<int> prime_list = primeList(is_prime);
    int ans = findSum(prime_list, n);

    //출력
    cout << ans;
}