#include <bits/stdc++.h>
using namespace std;

string timeConversion(string s) {
    
    char meridiem = s[8];       // 오전 오후 구분
   
    string hour; string min; string sec;
    s[2] = s[5] = s[8] = ' ';  // 시분초 공백으로 구분
     
    istringstream splitter(s);
    splitter >> hour >> min >> sec;
    
    if (meridiem == 'P' && stoi(hour) < 12) hour = to_string(stoi(hour) + 12);
    if (meridiem == 'A' && stoi(hour) >= 12) hour = "0" + to_string(stoi(hour) - 12);
    
    stringstream combiner;
    combiner << hour << ":" << min << ":" << sec;
    
    return combiner.str();
    
}