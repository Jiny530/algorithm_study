#include <iostream>
#include <cstdlib>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    while (abs(a-b) > 1)
    {
        answer++;
        a = (a+1)/2;
        b = (b+1)/2;
    }
    
    if (a%2 == 0 && a < b || b%2 == 0 && a > b)  answer++;

    return answer;
}