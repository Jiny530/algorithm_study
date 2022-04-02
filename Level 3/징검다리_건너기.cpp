#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool can_cross(vector<int>stones, int num, int k)
{
    int stone_num = 0;
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] < num) {
            stone_num++;
            if (stone_num == k) return false;
        }
        else stone_num = 0;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 1;
    int right = 2000000000;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (can_cross(stones, mid, k)) // mid 명이 징검다리를 건너갈 수 있음
        {
            answer = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    return answer;
}