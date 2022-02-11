#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    int id_len = id_list.size();

    // 신고받은 횟수 배열
    int* reported = new int[id_len];
    memset(reported, 0, sizeof(int) * id_len);

    // 중복신고 및 신고자 리스트를 확인하기 위한 2차원 배열
    int** reportCheck = new int* [id_len];

    // 유저 ID와 유저 ID 배열의 인덱스를 Map에 저장, ID로 인덱스에 접근하기 위함
    map<string, int> userIndex;
    for (int i = 0; i < id_len; i++) {
        
        userIndex.insert({ id_list[i],i });

        reportCheck[i] = new int [id_len];
        memset(reportCheck[i], 0, sizeof(int) * id_len); // 중복신고 체크 배열 초기화
    }

    string bf1, bf2;
    int idx1, idx2;
   
    for (int i = 0; i < report.size(); i++) {
        
        istringstream ss(report[i]);
        getline(ss, bf1, ' ');
        getline(ss, bf2, ' ');

        idx1 = userIndex[bf1];
        idx2 = userIndex[bf2];

        if (!reportCheck[idx1][idx2]) // 중복신고가 아니라면
        {
            reported[idx2] += 1; // 신고횟수 증가
            reportCheck[idx1][idx2] = 1; // 신고 표시 - 1이 2를 신고
        }
    }

    vector<int> answer(id_len); // 정답배열, 0으로 초기화

    for (int i = 0; i < id_len; i++)
    {
        if (reported[i] >= k)
        {
            for (int j=0; j<id_len; j++)
                if (reportCheck[j][i]) answer[j] += 1; // 신고한 사람 +1
        }
    }

    return answer;
}