#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> dp;
int get_dp(string target, vector<int> visit, vector<string> words, int curr)
{
    if (dp[curr] != -1) return dp[curr];
    if (words[curr] == target)
    {
        dp[curr] = 0;
        return dp[curr];
    }

    int answer = 1000;

    for (int i = 0; i < words.size(); i++)
    {
        if (visit[i] == 1) continue;

        int same = 0;
        for (int j = 0; j < target.size(); j++)
        {
            if (words[curr][j] != words[i][j]) same++;
        }
        if (same == 1) {
            visit[i] = 1;
            answer = min(get_dp(target, visit, words, i) + 1, answer);
            visit[i] = 0;
        }
    }

    dp[curr] = answer;
    return answer;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 1000;
    vector<int> dp_array(words.size(), -1);
    vector<int> visit(words.size(), -1);
    dp = dp_array;

    for (int i = 0; i < words.size(); i++)
    {
        int same = 0;
        for (int j = 0; j < target.size(); j++)
        {
            if (begin[j] != words[i][j]) same++;
        }
        if (same == 1)
        {
            visit[i] = 1;
            answer = min(get_dp(target, visit, words, i) + 1, answer);
            visit[i] = 0;
        }
    }

    if (answer == 1000) answer = 0;
    return answer;
}