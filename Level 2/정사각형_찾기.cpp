#include <iostream>
#include<vector>
using namespace std;
int wid, hei;
int find_square(int x, int y, int len, vector<vector<int>> board)
{
    int answer = 1;
    vector<int> counts(len, 1);
    for (int i = 0; i < len; i++)
    {
        int count = 0;
        for (int j = 1; j < len; j++)
        {
            if (x + j < hei && y + i < wid && board[x + j][y + i] == 1) {
                counts[i] += 1;
            }
            else break;
        }
    }

    int num = -1;
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (counts[i] > 0)
        {
            if (counts[i] == num)
            {
                count++;
                if (count >= num && num * num > answer)
                {
                    answer = num * num;
                    if (answer > len * len) goto EXIT;
                }
            }
            else {
                if (count >= num && num * num > answer)
                {
                    answer = num * num;
                    if (answer > len * len) goto EXIT;
                }
                else {
                    count = 1;
                    num = counts[i];
                }
            }
        }

    }
EXIT:
    return answer;
}
int solution(vector<vector<int>> board)
{
    int answer = 0;
    int x, y;
    hei = board.size();
    wid = board[0].size();

    for (int i = 0; i < board.size(); i++)
    {
        int len = 0;
        bool start = false;
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 1)
            {
                len += 1;
                if (!start) { 
                    x = i; y = j; 
                    start = true;
                }
                if (j == board[i].size() - 1)
                {
                    int temp = find_square(x, y, len, board);
                    if (temp > answer) answer = temp;
                }
            }
            else if (start)
            {
                int temp = find_square(x, y, len, board);
                if (temp > answer) answer = temp;
                start = false;
                len = 0;
            }
        }
    }

    return answer;
}

int main() {
    solution({ {0, 0, 1, 1},{1, 1, 1, 1} });
}