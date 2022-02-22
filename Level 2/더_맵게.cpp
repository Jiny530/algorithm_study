#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    int idx = 0;
    int newFood = 0;
    sort(scoville.begin(), scoville.end());

    while (scoville[idx] < K) {
        answer++;
        newFood = scoville[idx] + 2 * scoville[idx + 1];
        for (int i = idx + 2; i < scoville.size(); i++) {
            if (scoville[i] > newFood) {
                scoville.insert(i, newFood);
                break;
            }
        }
        idx += 2;
        if (idx > scoville.size()) break;
    }

    return answer;
}