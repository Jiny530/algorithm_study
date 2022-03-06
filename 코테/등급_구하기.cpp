#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

int greade(int money) {
    if (money < 10000) return 0;        // 브론즈
    else if (money < 20000) return 1;   // 실버
    else if (money < 50000) return 2;   // 골드
    else if (money < 100000) return 3;  // 플래티넘
    else return 4;                      // 다이아
}
vector<int> solution(vector<string> purchase) {
    vector<int> answer(5, 0);
    int n = purchase.size();

    vector<vector<int>> lists(n,vector<int>(2));
    int monthes[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int year, month, date, pay;
    
    for (int i = 0; i < n; i++) {
        purchase[i][4] = purchase[i][7] = ' ';
        istringstream ss(purchase[i]);
        ss >> year >> month >> date >> pay;

        int date_count = 0;
        for (int j = 0; j < month; j++) date_count += monthes[j];

        lists[i][0] = date_count + date;
        lists[i][1] = pay;
    }

    vector<vector<int>> accum_list;
    int money=0;
    int curr = 0;
    int late = 0; // 여기까지 날짜 계산 끝낸 날짜
    int accum_index = 0;

    for (int i = 0; i < n; i++) {

        curr = lists[i][0]; // 현재날짜

        // 누적중에 날짜 지난거 빼기
        for (int j = accum_index; j < accum_list.size(); j++) { 

            if (accum_list[j][0] + 30 > curr) break; // 아직 안지남

            answer[greade(money)] += accum_list[j][0] + 30 - late;
            money -= accum_list[j][1];
            late = accum_list[j][0] + 30;
            accum_index++;
        }
        answer[greade(money)] += lists[i][0] - late;
        accum_list.push_back(lists[i]);
        money += lists[i][1];
        late = curr;
    }

    for (int j = accum_index; j < accum_list.size(); j++) {

        answer[greade(money)] += accum_list[j][0] + 31 - late; // 고침
        money -= accum_list[j][1];
        late = accum_list[j][0] + 31;

    }
    answer[0] += 365 - late;
    return answer;
}