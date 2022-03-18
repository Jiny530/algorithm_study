#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

int get_case(vector<int> list, vector<vector<int>> banned_case, int idx)
{
    if (idx == banned_case.size()) return 1;

    int case_count = 0;
    for (int i = 0; i < banned_case[idx].size(); i++)
    {
        if (list[banned_case[idx][i]] == 0)
        {
            list[banned_case[idx][i]] = 1;
            case_count += get_case(list, banned_case, idx + 1);
            list[banned_case[idx][i]] = 0;
        }
    }
    return case_count;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<int>> banned_cases(banned_id.size(), vector<int>());

    for (int i = 0; i < banned_id.size(); i++)
    {
        for (int j = 0; j < user_id.size(); j++)
        {
            if (banned_id[i].size() != user_id[j].size()) continue;

            int idx = 0;
            for (int k = 0; k < user_id[j].size(); k++)
            {
                if (banned_id[i][k] == '*') idx++;
                else if (banned_id[i][k] == user_id[j][k]) idx++;
                else break;
            }
            if (idx == user_id[j].size()) banned_cases[i].push_back(j);
        }
    }

    vector<int> list(user_id.size(), 0);
    sort(banned_cases.begin(), banned_cases.end(), compare);
    answer = get_case(list, banned_cases, 0);

    return answer;
}