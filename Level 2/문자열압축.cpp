#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {

    int answer = s.size();

    // 압축단위가 문자열의 절반보다 길면 의미가 없음
    for (int i = 1; i <= s.size() / 2; i++)
    {
        int zip = 1; // 압축횟수
        int zip_len = 0; // 압축된 문자열 길이
        string comp; // 비교할 문자열

        // 압축단위로 나눈 몫 - 1 만큼 비교
        for (int j = 0; j < s.size() / i - 1; j++)
        {
            comp = s.substr(i * j, i);
            if (comp == s.substr(i * (j + 1), i)) zip++;
            else if (zip>1) { // 앞 문자열이 압축될 수 있으면 압축단위 + 압축횟수의 자릿수
                zip_len += i + (int)log10(zip) + 1;
                zip = 1;
            }
            else {
                zip_len += i; // 앞 문자열이 압축되지 않으므로 압축단위를 더함 
            }
        }
        // 모두 비교하고 마지막 비교문자열 처리
        zip > 0 ? zip_len += i + (int)log10(zip) + 1 : zip_len += i;
        // 나누어 떨어지지 않는 뒷자리는 그대로 더함
        zip_len += s.size() % i;
        // 가장 짧은 문자열
        if (answer > zip_len) answer = zip_len;
    }

    return answer;
}