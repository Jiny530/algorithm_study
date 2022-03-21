#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int range = 2*w + 1;
    int last = 1;
    for (int i=0; i<stations.size(); i++)
    {
        int need_station = stations[i] - w - last;
        if (need_station > 0) answer += (need_station + range - 1) / range;
        last = stations[i] + w + 1;       
    }
    
    if (last <= n) answer += (n - last + range) / range;
    
    return answer;
}