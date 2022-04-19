#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    // 먼저 끝내야 하는 기능 순서대로 배포일까지 남은 날짜를 구함
    // 앞에서 구한 날짜보다 작거나 같으면 count++, 더 크면 answer에 저장하고 새로 ++ 
    int relCount = 1;
    int relDate = (99 - progresses[0]) / speeds[0] + 1;
    
    for (int i=1; i<progresses.size(); i++){
        int date = (99 - progresses[i]) / speeds[i] + 1;
        
        if (relDate >= date) relCount++;
        else {
            answer.push_back(relCount);
            relCount = 1;
            relDate = date;
        }
    }
    answer.push_back(relCount);
    return answer;
}