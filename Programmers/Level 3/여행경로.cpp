#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int airlines;

vector<string> find_path(string departure, map<string, vector<string>> airline, vector<string> path, int remains) {

    for (int i = 0; i < airline[departure].size(); i++) {
        map<string, vector<string>> replic = airline;
        vector<string> curr_path = path;

        replic[departure].erase(replic[departure].begin() + i);
        curr_path.push_back(airline[departure][i]);

        vector<string> answer = find_path(airline[departure][i], replic, curr_path, remains - 1);
        if (answer.size() == airlines) return answer;
    }
    if (remains == 0) return path;
    else return {};
}
vector<string> solution(vector<vector<string>> tickets) {

    vector<string> answer;
    map<string, vector<string>> airline;
    map<string, vector<string>>::iterator iter;
    pair< map<string, vector<string>>::iterator, bool> inserter;

    airlines = tickets.size() + 1;

    // 각 항공에서 출발하는 항공선을 map으로 분류 (출발지, 도착지 배열)
    for (int i = 0; i < tickets.size(); i++) {
        inserter = airline.insert({ tickets[i][0], { tickets[i][1] } });
        if (!inserter.second) inserter.first->second.push_back(tickets[i][1]); // 이미 있는 출발지라면 도착지 배열에 추가만 해줌
    }

    // 도착 공항 알파벳순 정렬
    for (iter = airline.begin(); iter != airline.end(); iter++) {
        sort(iter->second.begin(), iter->second.end());
    }

    return find_path("ICN", airline, {"ICN"}, airlines - 1);

}