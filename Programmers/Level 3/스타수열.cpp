#include <string>
#include <vector>

using namespace std;
int solution(std::vector<int> a) {
    int answer = 0;
    
    // 짝을 이룰 수 있는 개수
    vector<vector<int>> pair_count(a.size(), vector<int>(1, 0));

    int before = a[0]; // 이전 숫자
    int before_pair = -1; // 이전 숫자와 짝을 이루는 숫자의 인덱스
    int before_before_pair = -1; // 이전숫자와 짝을 이루는 숫자의 짝 인덱스

    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == before) before_pair = -1;

        else if (a[i] != before)
        {
            // 이전 숫자가 짝을 이루지 않고 있으면 각각 짝 개수 증가
            if (before_pair == -1)
            {
                pair_count[before][0] += 1;
                pair_count[a[i]][0] += 1;
                before_before_pair = i;
                before_pair = i - 1;
            }
            // 이전 숫자의 짝이 현재 숫자와 다른 숫자이거나
            // 같은 숫자더라도 그 짝이 이전숫자가 아니라면 현재 숫자가 짝을 이룰 수 있음
            else if (a[before_pair] != a[i] || before_before_pair != i - 1) {
                pair_count[a[i]][0] += 1;
                before_before_pair = before_pair;
                before_pair = i - 1;
            }
            // 현재 숫자가 짝을 이루지 못했음
            else {
                before_pair = -1;
            }
            before = a[i];
        }
    }

    int count = 0;
    for (int i = 0; i < a.size(); i++) count = max(pair_count[i][0], count);
    if (count < 2) answer = 0;
    else answer = count * 2;

    return answer;
}