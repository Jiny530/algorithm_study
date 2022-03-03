#include <string>
#include <vector>
#include <map>

using namespace std;
struct node {
    char opponent;
    int *intervals;
};
vector<int> intervals(char sign, int range, int n) {
    
    vector<int> interval;
    switch (sign) {
    case '=':
        interval.push_back(range);
        return interval;
    case '<':
        for (int i=0; i<range; i++) interval.push_back(i);
        return interval;
    case '>':
        for (int i = range+1; i <= n; i++) interval.push_back(i);
        return interval;
    }
}

vector<int> intersections(vector<int> one, vector<int> two) {
    vector<int> intersect;

    for (int i = 0; i < one.size(); i++) {
        for (int j = 0; j < two.size(); j++) {
            if (one[i] == two[j]) {
                intersect.push_back(one[i]);
                break;
            }
        }
    }
    return intersect;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    // A~B<3
    map<string, vector<int>> conditions;
    pair<map<string, vector<int>>::iterator, bool> iter;
    string key = "";

    // 조건 합치기
    for (int i = 0; i < n; i++) {
        // 문자 순서가 빠른 순으로 나열하여 key 생성. ex) "AB"
        if (data[i][0] < data[i][2]) key = data[i][0] + data[i][2];
        else key = data[i][2] + data[i][0];

        vector<int> interval = intervals(data[i][3], data[i][4] - 48, n);
        iter = conditions.insert({ key, interval }); // 문자 1~9의 아스키코드값에서 숫자 1~2로 변환

        if (!iter.second) { // 이미 조건이 있다면 둘의 교집합을 넣기
            conditions[key] = intersections(interval, conditions[key]);
            if (conditions[key].size() == 0) return 0; // 교집합이 없다면 자리배치 불가능
        }
    }

    // 자리 배치
    map<string, vector<int>>::iterator it = conditions.begin();
    bool temp[9] = { 0,0,0,0,0,0,0,0,0 };
    while (it != conditions.end()) {
        map<char, int> order;
        for (int i = 0; i < it->second.size(); i++) {
            for (int t = 1; t < 9; t++) { // 앞문자
                if (temp[t] == 0) {
                    order[it->first[0]] = t;
                    break;
                }
            }

            
        }
        ++it;
    }


    return answer;
}

int ordering(char one, char another, int interval, map<char, int>* order, bool** temp) {
    
    int count = 0;
    map<char, int>::iterator it1, it2;
    it1 = order->find(one);
    it2 = order->find(another);

    if (it1!=order->end()) { // 가 이미 자리를 배정받았고 
        if (it2->second - interval > 0);
        if (it2->second + interval < 9); //dfs?
        return count;
    }
    else {
        for (int k = 1; k < 9; k++); //dfs
        return count;
    }
}