#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int N, int number) {

    map<int, int> numbers;
    vector<vector<int>> dp(9,vector<int>()); // 인덱스는 1~8을 사용
    map<int, int>::iterator iter;

    string n = "";
    for (int i = 1; i < 9; i++) { // n, nn, nnn ... 집어넣기
        n += "1";
        dp[i].push_back(N * stoi(n));
        numbers.insert({ dp[i][0], i });
    }

    for (int i = 2; i < 9; i++) { // N의 최대개수인 8개까지 반복
        for (int j = 1; j <= i / 2; j++) { // 더해서 i가 되는 두 숫자쌍의 개수만큼 반복
            for (int k = 0; k < dp[j].size(); k++) { // j와 i-j의 사칙연산
                for (int m = 0; m < dp[i - j].size(); m++) {
                    if (dp[i - j][m] == 0 || dp[j][k] == 0) continue;

                    dp[i].push_back(dp[j][k] + dp[i - j][m]);
                    dp[i].push_back(dp[j][k] - dp[i - j][m]);
                    dp[i].push_back(dp[j][k] * dp[i - j][m]);
                    dp[i].push_back(dp[j][k] / dp[i - j][m]);
                    dp[i].push_back(dp[i-j][m] / dp[j][k]);
                    dp[i].push_back(dp[i - j][m] - dp[j][k]);

                    for (int p = dp[i].size() - 7; p < dp[i].size(); p++) {
                        numbers.insert({ dp[i][p], i }); // 한번에 집어넣기
                    }
                }
            }
        }
        iter = numbers.find(number); // number가 만들어졌다면 다음 반복 없이 종료
        if (iter != numbers.end()) return iter->second;
    }
    return -1;
}