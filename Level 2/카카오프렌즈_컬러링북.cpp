#include <vector>

using namespace std;
int row, col;

int countingArea(int r, int c, vector<vector<int>>& pic, vector<vector<int>> &isCh) {
    int area_size = 1;
    isCh[r][c] = 1;
    
    if (r > 0 && !isCh[r - 1][c] && pic[r-1][c] == pic[r][c]) {
        area_size += countingArea(r - 1, c, pic, isCh); // 상
    }
    if (r < row-1 && !isCh[r + 1][c] && pic[r + 1][c] == pic[r][c]) {
        area_size += countingArea(r + 1, c, pic, isCh); // 하
    }
    if (c > 0 && !isCh[r][c - 1] && pic[r][c-1] == pic[r][c]) {
        area_size += countingArea(r, c-1, pic, isCh); // 좌
    }
    if (c < col - 1 && !isCh[r][c+1] && pic[r][c+1] == pic[r][c]) {
        area_size += countingArea(r, c+1, pic, isCh); // 우
    }
    return area_size;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int num_area = 0;
    int max_size = 0;
    int area_size;
    row = m;
    col = n;
    
    vector<vector<int>> isChecked(m, vector <int>(n, 0)); // 방문 여부 확인
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 영역 탐방
            if (picture[i][j] && !isChecked[i][j]) {
                num_area += 1;
                area_size = countingArea(i, j, picture, isChecked);
                if (max_size < area_size) max_size = area_size;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = num_area;
    answer[1] = max_size;
    return answer;
}