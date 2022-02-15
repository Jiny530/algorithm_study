#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    int len = lines.size();

    double* compTime = new double[len]; // 완료시각을 모두 더하여 sec 단위로 나타낸 값
    double* procTime = new double[len]; // 처리시간 
    int hour, min, sec;

    for (int i = 0; i < len; i++) {
        lines[i][13] = lines[i][16] = ' '; // :를 공백으로 바꿔 시분초를 각각 나눠 저장함
        istringstream ss(lines[i]);
        string date;
        ss >> date >> hour >> min >> sec >> procTime[i];
        compTime[i] = hour * 360.0 + min * 60.0 + sec;
    }

    // 완료시점이 빠른 순으로 정렬
    sort(compTime, compTime + len);
    // 현재 인덱스의 뒷 요청들의 시작시간이 현재 인덱스의 완료시점 + 1초 보다 작은 것들의 개수를 구하기
    int max;
    for (int i = 0; i < len; i++) {
        max = 1;
        for (int j = i+1; j < len; j++) {
            if (compTime[j] - procTime[i] < compTime[i] + 1) max++;
        }
        if (answer < max) answer = max;
    }
    return answer;
}