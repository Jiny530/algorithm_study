#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int len = skill.size();

    for (int i = 0; i < skill_trees.size(); i++)
    {
        int idx = 0; // 스킬트리 순서를 나타낼 인덱스
        for (int j = 0; j < skill_trees[i].size(); j++)
        {
            int order = skill.find(skill_trees[i][j]);
            if (order != string::npos)
            {
                if (order != idx) break;
                else idx++;
            }
            
            if (idx == len)
            {
                answer++;
                break;
            }
            
            if (j == skill_trees[i].size() - 1)
            {
                answer++;
                break;
            }

        }
    }

    return answer;
}