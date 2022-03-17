#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    
    if (s<n) return { -1 };
    
    int share = s / n;
    int remain = s % n;
    vector<int> answer(n,share);
    
    for (int i=n-1; i>=n-remain; i--) answer[i] += 1;
    
    return answer;
}