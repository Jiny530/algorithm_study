#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    // id와 닉네임 map 생성
    map<string, string> nickname;
    // record 문자열 분할
    string action, id, name;

    for (int i = 0; i < record.size(); i++)
    {
        istringstream ss(record[i]);
        ss >> action >> id >> name;

        if (action == "Enter") {
            nickname[id] = name;
            answer.push_back(id + "님이 들어왔습니다.");
        }
        else if (action == "Leave") {
            answer.push_back(id + "님이 나갔습니다.");
        }
        else if (action == "Change") {
            nickname[id] = name;
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        int len;
        string key;

        len = answer[i].find("님"); // ~님 바로 앞까지가 id 길이
        key = answer[i].substr(0, len);
        answer[i].replace(0, len, nickname[key]);
    }

    return answer;
}