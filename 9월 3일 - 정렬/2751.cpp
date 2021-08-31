#include <iostream>
#include <vector>

using namespace std;

//정렬할 배열, 정렬한 배열
vector<int> arr, sorted;

//start ~ end 사이의 배열을 출력하는 함수
void printArr(int start, int end, string tag) {
    cout << tag << " array : ";
    for (int i = start; i <= end; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

//합병 정렬(conquer, merge)
void merge(int left, int mid, int right) {
    //왼쪽 배열, 오른쪽 배열, 합친 배열의 가장 왼쪽을 가리킴
    int p1 = left, p2 = mid + 1, p3 = left;

    //왼쪽 & 오른쪽 배열 중 하나라도 원소를 다 사용하면 반복문 탈출
    //왼쪽 배열의 범위 : left ~ mid, 오른쪽 배열의 범위 : mid+1 ~ right
    while (p1 <= mid && p2 <= right) {
        if (arr[p1] <= arr[p2]) //왼쪽 배열의 값이 오른쪽 배열의 값보다 작거나 같음
            sorted[p3++] = arr[p1++];
        else //왼쪽 배열의 값이 오른쪽 배열의 값보다 큼
            sorted[p3++] = arr[p2++];
    }
    while (p1 <= mid) //왼쪽 배열에 탐색하지 않은 원소가 남아있나?
        sorted[p3++] = arr[p1++];
    while (p2 <= right) //오른쪽 배열에 탐색하지 않은 원소가 남아있나?
        sorted[p3++] = arr[p2++];
    //sorted 배열을 따로 쓰지 않고 arr에 그대로 반영하면 안된다는 얘기를 언급할 생각입니다(튜터용)
    for (int i = left; i <= right; i++) //sorted -> arr 복사
        arr[i] = sorted[i];
}

//합병 정렬(divide)
//재귀 함수는 아무래도 이해가 반복문보다는 어려워서 출력도 해보고, 아무튼 설명을 많이 할 예정입니다(튜터용)
void mergeSort(int left, int right) {
    if (left < right) { //더 나눌 수 있다면
        int mid = (left + right) / 2; //정확히 둘로 나눈다
        mergeSort(left, mid); //왼쪽 배열
        mergeSort(mid + 1, right); //오른쪽 배열

        //정렬 전 배열 출력
        //이 부분 함수화 하는 것도 보여줄까 합니다(튜터용)
        printArr(left, mid, "Left");
        printArr(mid + 1, right, "Right");

        merge(left, mid, right); //합치기

        //정렬 후 배열 출력
        printArr(left, right, "Merged");
        cout << '\n';
    }
}

//이 코드 리팩토링 해서 sort 함수 사용하는거 보여줄 거예요...!(튜터용)
int main() {
    int n;

    //입력
    cin >> n;
    arr.assign(n, 0);
    sorted.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    mergeSort(0, n - 1);

    //출력
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}