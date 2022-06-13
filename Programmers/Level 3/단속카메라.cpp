#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    if (a[0] == b[0]) return a[1] > b[1];   // 진입 시점이 같다면 더 늦게 진출되는 차량 순으로 정렬
    else return a[0] < b[0];    // 더 일찍 진입하는 차량 순으로 정렬
}
int solution(vector<vector<int>> routes) 
{
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    
    int out = routes[0][1];
    for (int i=1; i<routes.size(); i++)
    {
        // 다음 차량의 진입지점이 현재 진출지점보다 늦으면 카메라 설치
        if (routes[i][0] > out)
        {
            answer++;
            out = routes[i][1];
        }
        // 다음 차량의 진출지점이 현재 진출지점보다 빠르면 진출지점 업데이트
        else if (routes[i][1] < out)
        {
            out = routes[i][1];
        }
        // 다음 차량의 진출지점이 현재 진출지점보다 늦으면 다음 반복으로 넘어감
    }
    
    answer++;   // 마지막 진출지점에 카메라 설치
    return answer;
}