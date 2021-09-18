#include <iostream>
#include <vector>

using namespace std;
const int MAX = 9;

bool found = false; //스도쿠를 다 채웠는지 확인

/**
 * 같은 행, 열, 구역에 이미 같은 숫자가 있다면 false 리턴
 *
 * 숫자를 입력하려 하는 칸이 (row, col)일 때
 * 같은 행 : (row, 0~8)
 * 같은 열 : (0~8, col)
 *
 * 같은 구역
 * 스도쿠의 크기는 9x9, 같은 구역의 크기는 3x3
 * row = 1, col = 1일 때, 같은 구역은 (0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2), (2, 0), (2, 1), (2, 2)
 * 공통점 : 행과 열을 3으로 나눈 몫이 같음 (0, 0)
 */
bool promising(vector<vector<int>> &sudoku, int row, int col, int num) {
    for (int i = 0; i < MAX; i++) { //같은 행과 열에 이미 같은 숫자가 있는지 확인
        if (sudoku[i][col] == num || sudoku[row][i] == num)
            return false;
    }

    //같은 구역(3x3)에 이미 같은 숫자가 있는지 확인
    int row_area = row / 3, col_area = col / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[row_area * 3 + i][col_area * 3 + j] == num)
                return false;
        }
    }
    return true;
}

/**
 * (튜터용)
 * promsing 함수를 이걸로 하면 TLE가 발생하거든요. 근데 진짜 이유를 모르겠어요
 * 아무리 많이 반복문을 돌아도 81인데 겨우 그걸로 시간초과인가 싶으면서도 얘만 고치면 해결되거든요...
 * 제가 뭘 잘못한걸까요??
 * 저 위에 promising 함수에서 구역 체크하는 부분 3*3아니고 9*9로 바꿔도 384ms인데 얘 꾸역꾸역 수정해서 돌아가게 만들었을 때가 996ms였어요,,,
 */
bool promisingTLE(vector<vector<int>> &sudoku, int row, int col, int num) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i == row && j == col)
                continue;
            if ((i == row || j == col) && (sudoku[i][j] == num))
                return false;
            if ((i / 3 == row / 3) && (j / 3 == col / 3) && (sudoku[i][j] == num))
                return false;
        }
    }
    return true;
}

/**
 * 스도쿠의 칸 81개를 하나씩 확인하며 빈공간이라면 숫자를 채움
 *
 *    (행, 열)      인덱싱
 * (0, 0) (0, 1)    0 1
 * (1, 0) (1, 1)    2 3
 *
 * 행을 i, 열을 j라고 하면, 해당 칸의 인덱스는 (i*(판의 크기)+j)로 나타낼 수 있음
 * -> 인덱스 k가 있을 때, 이를 행과 열로 바꾸면 (k/(판의 크기), k%(판의 크기))
 *
 * 스도쿠 판의 마지막 칸은 (8, 8) -> 80
 * 그러므로 종료조건은 k==81
 */
void fillSudoku(vector<vector<int>> &sudoku, int idx) {
    if (idx == MAX * MAX) { //종료조건 : 마지막 칸까지 숫자를 채움
        found = true;
        return;
    }
    int row = idx / MAX; //이번 칸의 행
    int col = idx % MAX; //이번 칸의 열

    if (sudoku[row][col]) //이미 숫자가 채워진 칸이라면 다음 칸으로 넘어감
        return fillSudoku(sudoku, idx + 1);
    for (int i = 1; i <= MAX; i++) { //1~9까지 넣어보기
        if (!promising(sudoku, row, col, i)) //이 칸에 숫자 i를 넣을 수 없음
            continue;

        sudoku[row][col] = i; //숫자 적기
        fillSudoku(sudoku, idx + 1); //다음 칸으로 넘어감
        if (found) //생각해보기 : 이 부분이 없으면 어떻게 될까요?
            return;
        sudoku[row][col] = 0; //숫자 지우기
    }
}

int main() {
    vector<vector<int>> sudoku(MAX, vector<int>(MAX, 0));

    //입력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cin >> sudoku[i][j];
    }

    //연산
    fillSudoku(sudoku, 0);

    //출력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }
}