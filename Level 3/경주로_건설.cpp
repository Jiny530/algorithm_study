#include <string>
#include <vector>

using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<int>> state;
int n;

int dfs(vector<vector<int>> visit, int before, int x, int y)
{
    if (x == n - 1 && y == n - 1) return 100;
    visit[x][y] = 1;
    int answer = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (visit[nx][ny] + state[nx][ny] > 0) continue;

        int road = dfs(visit, i, nx, ny);
        if (road == 0) continue;
        else road += before == i ? 100 : 600;
        if (answer == 0 || answer > road) answer = road;
    }
    
    return answer;
}
int solution(vector<vector<int>> board) {
    state = board;
    n = board.size();
    vector<vector<int>> visit(n, vector<int>(n, 0));
    int answer = 0;

    visit[0][0] = 1;
    for (int i = 0; i < 2; i++)
    {
        int x = dx[i];
        int y = dy[i];
        if (board[x][y] == 1) continue;
        int road = dfs(visit, i, x, y);
        if (answer == 0 || answer > road) answer = road;
    }

    return answer;
}