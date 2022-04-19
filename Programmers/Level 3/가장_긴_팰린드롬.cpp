#include <iostream>
#include <string>
#include <map>
using namespace std;

// 시간초과, dp와 합쳐봐야 할 것 같은데 아직 모르겠음
map<string, int> dp;
int getPalindrome(string s)
{
    if (s.size() <= 1) return s.size();

    int max = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = s.size() - 1; j > i; j--)
        {
            if (s[i] == s[j])
            {
                string sub_string = s.substr(i + 1, j - i - 1);
                // 앞뒤로 똑같은 문자가 나오면 그 안에 있는 문자열에서 또 팰린드롬을 찾음
                int palindrome = getPalindrome(s.substr(i + 1, j - i - 1));
                max = palindrome > max ? palindrome : max;
            }
        }
    }

    if (max == 0) return 1; // 길이가 1보다 크지만 똑같은 문자가 없을 경우 최대 1개만 포함 가능
    else return max + 2;
}
int solution(string s)
{
    int answer = 0;
    answer = getPalindrome(s);
    return answer;
}