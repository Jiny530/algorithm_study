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
        if (scoville.size() == idx + 1) return -1;
        answer++;
        newFood = scoville[idx] + 2 * scoville[idx + 1];
        if (scoville.size() == idx + 2) {
            if (newFood >= K) break;
            else return -1;
        }
        for (int i = idx + 2; i < scoville.size(); i++) {
            if (scoville[i] > newFood) {
                scoville.insert(scoville.begin() + i, newFood);
                break;
            }
            if (i == scoville.size()-1) {
                scoville.push_back(newFood);
                break;
            }
        }
        idx += 2;
    }
    return answer;
}