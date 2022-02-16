#include <string>
#include <vector>
#include <regex>

using namespace std;
int solution(string s){
    string str[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i=0; i < 10; i++){
        s = regex_replace(s, regex(str[i]), to_string(i));
    }
    return stoi(s);
}

// if-else문 덕지덕지 하지 말기
// find + replace + 반복을 수행하는 regex_replace