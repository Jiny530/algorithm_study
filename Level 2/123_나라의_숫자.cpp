#include <string>
#include <vector>

using namespace std;
//아직 푸는중

string solution(int n) {
    string answer = "";
    string reverse = "";
    int share;
    int remain = n%3;
    
    remain ? reverse += to_string(remain) : reverse += "4";    
    // 20 = 1 4 2
    // 6 ... 2
    // 2 ... 0
    // 0 ... 2
    
    while(n>0) {
        share = n/3;
        remain = n%3;
        if (remain==0) reverse += to_string(remain);
        reverse += to_string(remain);
        n = n/3;
    } 
    
    for (int i=reverse.size()-1; i>=0; i--){
        if (reverse[i]=='0') answer += "4";
        else answer += reverse[i];
    }
    
    return answer;
}