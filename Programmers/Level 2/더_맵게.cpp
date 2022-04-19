#include <string>
#include <vector>
#include <functional> 
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }

    int first, second, sum;
    while (pq.top() < K)
    {
        first = pq.top();
        pq.pop();
        if (pq.empty()) return -1;

        second = pq.top();
        pq.pop();

        sum = first + second * 2;
        pq.push(sum);
        answer++;
    }

    return answer;
}