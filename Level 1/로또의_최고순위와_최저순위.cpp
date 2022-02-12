#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int zero = 0;
    int correct = 0;

    for (int i=0; i<6; i++)
    {
        if (lottos[i]==0) // 알아볼 수 없는 숫자
        {
            zero++;
            continue;
        }

        for (int j=0; j<6; j++)
        {
            if (lottos[i] == win_nums[j]) correct++; // 일치하는 숫자
        }
    }

    answer.push_back(correct+zero > 1 ? 7-correct-zero : 6);
    answer.push_back(correct > 1 ? 7-correct : 6);

    return answer;
}
