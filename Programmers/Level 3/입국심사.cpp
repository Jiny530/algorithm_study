#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool check(long long minute, vector<int> times, int n)
{
    long long sum = 0;
    for (int i = 0; i < times.size(); i++)
    {
        sum += minute / times[i];
        if (sum >= n) return true;
    }
    return false;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());
    long long left = 1;
    long long right = 1e18;
    long long min, mid;
    
    while (left <= right)
    {
        mid = (left + right) / 2;
       
        if (check(mid, times, n)) {
            min = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return min;
}
