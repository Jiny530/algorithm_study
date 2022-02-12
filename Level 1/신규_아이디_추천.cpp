#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    bool isDot = false;

    for (int i = 0; i < new_id.size(); i++) {
        // 대->소문자 치환
        if (new_id[i] >= 65 && new_id[i] <= 90) {
            answer += (char)(new_id[i] + 32);
            isDot = false;
        }

        // 허용문자 이외 모든문자 제거
        else if ((new_id[i] >= 48 && new_id[i] <=57) || (new_id[i] >= 97 && new_id[i] <= 122) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            // 연속마침표 제거
            if (isDot && new_id[i] == '.') continue;
            else if (new_id[i] == '.') isDot = true;
            else isDot = false;

            answer += new_id[i];
        }
    }

    // 처음과 끝의 마침표 제거
    if (answer.front() == '.') answer.erase(0,1);
    if (answer.back() == '.') answer.erase(answer.size()-1,1);

    // 16자 이상이면 인덱스 15 이후로 제거, 15번째가 마침표라면 같이 제거
    if (answer.size() > 15) {
        if (answer[14] == '.') answer.erase(14,answer.size()-14);
        else answer.erase(15,answer.size()-15);
    }
    else if (answer.size() == 0) answer += "a"; // 빈문자열은 a 넣기

    // 2자 이하일 경우 마지막문자를 3자 될때까지 반복
    while(answer.size() < 3)
        answer += answer.back();

    return answer;
}
