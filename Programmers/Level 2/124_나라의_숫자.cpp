#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string answer = "";
    string reverse = "";
    int remain;
    
    while(n>0) {
        remain = n % 3;
        if (remain==0) { // 나누어 떨어지면
            n = n / 3 - 1; // 몫에서 1 제외
            reverse += "4";
        }
        else { // 나누어 떨어지지 않으면 그대로
            n = n / 3;
            reverse += to_string(remain);
        }
    } 
    for (int i = reverse.size() - 1; i >= 0; i--){
        answer += reverse[i]; // reverse 하지 않고 answer = remain + answer 하면 더 좋을 것
    }
    return answer;
}