#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string, int> list;
    pair<map<string, int>::iterator, bool> iter1;
    
    // 완주한 사람들을 맵에 넣기
    for (int i = 0; i < completion.size(); i++) {
        iter1 = list.insert({ completion[i], 1 });
        if (!iter1.second) list[completion[i]]++; // 동명이인이 있다면 숫자 증가
    }

    map<string, int>::iterator iter2;
    // 전체 참가자와 완주자 비교
    for (int i = 0; i < participant.size(); i++) {
        iter2 = list.find(participant[i]);

        if (iter2 == list.end()) return participant[i];
        else if (list[participant[i]] == 1) list.erase(iter2); // 동명이인인 경우
        else list[participant[i]]--;
    }
    return answer;
}