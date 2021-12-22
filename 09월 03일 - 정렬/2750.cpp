#include <iostream>
#include <vector>

using namespace std;

//정렬할 배열
vector<int> arr;

//버블 정렬
void bubbleSort(int n) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        //0 ~ n-1까지 정렬 -> 0 ~ n-2까지 정렬 -> ... -> 0 ~ 1까지 정렬
        for (int j = 1; j < n - i; j++) {
            if (arr[j - 1] > arr[j]) {
                //이 부분 먼저 이렇게 짜고 swap 함수 보여줄 예정입니다(튜터용)
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
                //swap(arr[j-1], arr[j]);
            }
            cnt++;
        }
    }
    //향상된 버블 정렬과 비교하기 위해서(튜터용)
    //함수안에서 출력하는건 바람직하지 않지만 디버깅용인 셈이라고 설명하려고 합니다(튜터용)
    cout << "Calculation : " << cnt << '\n';
}

//향상된 버블 정렬
void bubbleSortAdv(int n) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 1; j < n - i; j++) {
            if (arr[j - 1] > arr[j]) {
                flag = false;
                swap(arr[j - 1], arr[j]);
            }
            cnt++;
        }
        //flag == true -> 모든 원소가 오름차순이므로 더이상 연산할 필요가 없다.
        //원래 break 아니고 return으로 했는데 그럼 아래 출력문이 실행 안돼서 break로 했어요! 튜터링 중에도 설명할 예정입니다. return 권장(튜터용)
        if (flag)
            break;
    }
    //향상된 버블 정렬과 비교하기 위해서(튜터용)
    cout << "Calculation : " << cnt << '\n';
}

int main() {
    int n;

    //입력
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    bubbleSort(n);
    //bubbleSortAdv(n);

    //출력
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}