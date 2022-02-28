#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int N, int number) {
    int answer = 0;

    // 푸는중
    
    // 최소값 찾기 -> 쓸때없이 많은 연산을 거치지 않아도 됨
    // 만들 수 있는 수
    // n이 한개일때 = n
    // n이 두개일때 = nn, 사칙연산 +*/ => -는 0이되므로 무의미
    // n이 세개일때 = nnn, 한개와 두개의 사칙연산. DP를 사용
    // n이 네개일때 = nnnn, 한개와 세개, 두개와 두개의 사칙연산
    // 각 dp가 모두 채워졌을때 number가 map에 들어있는지 확인
    // 나타낼 숫자, N이 쓰인 개수로 map<int,int> 생성

    // dp1의 개수만큼 반복
    // dp2와 dp1의 개수만큼 반복
    // dp2와 dp2, dp1와 dp3의 개수만큼 반복............

    
    map<int, int> numbers;
    vector<vector<int>> dp(9,vector<int>());

    string n = "";
    int num;
    for (int i = 1; i < 9; i++) {
        n += "1";
        num = N * stoi(n);
        numbers.insert(num, i);
        dp[i - 1].push_back(num);
    }

    dp[1].push_back(N + N);
    dp[1].push_back(N * N);
    dp[1].push_back(N / N);

    for (int i = 0; i < 3; i++) {
        numbers.insert(dp[1][i], 2);
    }


    for (int i = 1; i < 9; i++) { // N의 최대개수인 8번만큼 반복
        for (int j = 0; j < i / 2; j++) { // 더해서 i가 되는 두 숫자쌍의 개수만큼 반복
            for (int k = 0; k < dp[j].size(); k++) { // j와 i-j의 사칙연산
                for (int m = 0; m < dp[i - j].size(); m++) {
                    num = dp[j][k] + dp[i - j][m];
                    dp[i].push_back(num);

                }
            }
        }
    }


    return -1;
}