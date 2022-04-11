#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[500][500];
vector<vector<int>> nums;
int getDP(int row, int col)
{    
    if (row == nums.size() || dp[row][col] != 0) return dp[row][col];
    
    dp[row][col] = nums[row][col] + max(getDP(row+1, col), getDP(row+1, col+1));
    return dp[row][col];    
}
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    nums = triangle;
    
    for (int i=0; i<n; i++)
    {
        dp[n-1][i] = triangle[n-1][i];
    }
    
    answer = getDP(0,0);   
    return answer;
}