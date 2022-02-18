#include <vector>
#include <queue>

using namespace std;
int countingArea(int row, int col, vector<vector<int>> isChecked) {
    // 큐를 사용, 상-하-좌-우 순서로 넣기
    isChecked[row][col] = 1;

    return 1;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int num_area = 0;
    int max_size = 0;

    // 체크여부를 나타내는 배열

    vector<vector<int>> isChecked(m, n); // 방문 여부 확인
    queue<int> area;
    int area_size;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 영역 탐방
            if (picture[i][j] && !isChecked[i][j]) {
                num_area += 1;
                area_size = countingArea(i, j, isChecked);
                if (max_size < area_size) max_size = area_size;
            }
        }

    }


    vector<int> answer(2);
    answer[0] = num_area;
    answer[1] = max_size;
    return answer;
}