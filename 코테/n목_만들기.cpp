#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { 1,1,1,0,0,-1,-1,-1 };

int hei;
int wei;

vector<vector<int>> dp(10000000, vector<int>(9, 0));

int dpN(int i, int j, vector<string> board, int k) {

    if (dp[i*wei+j][k] != 0) return dp[i * wei + j][k];
    int x = i + dx[k];
    int y = j + dy[k];
    cout << x << " " << y << endl;
    if (x < 0 || x >= hei || y < 0 || y >= wei) dp[x * wei + y][k] = 0;
    else if (board[x][y] == '1') dp[x * wei + y][k] = dpN(x, y, board, k) + 1;

    return dp[x * wei + y][k];
}

int solution(int h, int w, int n, vector<string> board) {
    int answer = 0;
    hei = h;
    wei = w;
    for (int i = 0; i < h; i++) { 
        for (int j = 0; j < w; j++) { // 모든 보드를 살펴보기
            if (board[i][j] == '1') { // 그 중 n목을 만들 수 있는 1이 적힌 칸만 살펴봄
                for (int k = 0; k < 8; k++) { // 가로, 세로, 대각선을 모두 살피기 위해 8번 반복

                    int x = i + dx[k]; int y = j + dy[k];
                    if (x < 0 || x >= h || y < 0 || y >= w) continue; // 보드를 벗어나는 범위
                    // 가로, 세로, 대각선 방향의 1 개수 구하기 (현재 칸 포함 X)
                    if (board[x][y] == '0') dp[i * w + j][k] = 0;
                    else dp[i * w + j][k] = dpN(x, y, board, k) + 1; 
                }
                for (int q = 0; q < 4; q++) {
                    if (dp[i * w + j][q] == 0 && dp[i * w + j][7 - q] == n - 1) answer += 1;
                }
            }
        }
    }
    return answer;
}

int main() {
    vector<string> board = { "1111","1100","1010","1001" };
    cout << solution(4, 4, 4, board);
}