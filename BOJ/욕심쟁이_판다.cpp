#include <iostream>
#include <algorithm>
using namespace std;

int f_size;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int panda_road(int** forest, int** dp, int x, int y)
{
	// 이미 dp가 정해진 곳은 더 계산 안해도 됨
	if (dp[x][y] != 1) return dp[x][y];

	int px, py;
	for (int i = 0; i < 4; i++) {
		px = x + dx[i];
		py = y + dy[i];
		if (px >= 0 && px < f_size && py >= 0 && py < f_size && forest[x][y] > forest[px][py]) {
			// 현재 숲 주위에 더 작은 숲이 있으면, 그 숲들의 dp값 중 최대인 것을 찾아 +1 
			dp[x][y] = max(dp[x][y], panda_road(forest, dp, px, py) + 1);
		}
	}
	return dp[x][y];	
}
int main() {

	cin >> f_size;
	int panda_max = 0;

	int ** forest = new int*[f_size]; // 대나무숲
	int ** dp = new int* [f_size]; // 최대로 살 수 있는 값

	for (int i = 0; i < f_size; i++)
	{
		forest[i] = new int[f_size];
		dp[i] = new int[f_size];
		for (int j = 0; j < f_size; j++)
		{
			cin >> forest[i][j];
			dp[i][j] = 1;
		}
	}

	for (int i = 0; i < f_size; i++) {
		for (int j = 0; j < f_size; j++) {
			cout << i << j << endl;
			panda_max = max(panda_max, panda_road(forest, dp, i, j));
		}
	}	
	cout << panda_max;
}