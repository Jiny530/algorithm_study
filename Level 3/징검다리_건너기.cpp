#include <string>
#include <vector>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer =2000000001;
    
    for(int i=0; i<stones.size()-k+1; i++)
    {
        if (stones[i+k-1]>=answer) continue;
        int max=0;
        for(int j=i; j<i+k; j++) 
        {
            if (max<stones[j]) max= stones[j];
        }
        if (answer>max) answer = max;
    }
    
    return answer;
}