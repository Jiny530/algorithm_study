#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct index
{
	int tree;
	int row;
	int col;
};
// 정렬된 값과, 정렬되지 않은 원래의 값과, 정렬되지 않은 원래의 값이 가지고 있는 정렬된 값이 필요.
bool cmp(const index& a, const index& b)
{
	return a.tree < b.tree;
}
int f_size;
int panda_road(int** forest, vector<index> sorted, vector<int> &maxVal, int curr) 
{
	int r = sorted[curr].row;
	int c = sorted[curr].col;
	int i = r * f_size + c;
	int max_road = 0;

	// 상하좌우에 더 작은 숲이 있으면 그 숲의 최대 길찾기 값 +1
	if (r > 0 && forest[r - 1][c] < sorted[curr].tree) {
		max_road = max(max_road, maxVal[i-f_size] + 1); // 상
	}
	if (r < f_size - 1 && forest[r + 1][c] < sorted[curr].tree) {
		max_road = max(max_road, maxVal[i + f_size] + 1); // 하
	}
	if (c > 0 && forest[r][c - 1] < sorted[curr].tree) {
		max_road = max(max_road, maxVal[i - 1] + 1); // 좌
	}
	if (c < f_size - 1 && forest[r][c + 1] < sorted[curr].tree) {
		max_road = max(max_road, maxVal[i + 1] + 1); // 우
	}

	// 주변에 더 작은 숲이 없으면 1 반환
	if (max_road == 0) maxVal[i] = 1;
	else maxVal[i] = max_road;
	
	return maxVal[i];
	
}
int main() {

	cin >> f_size;
	int panda_max = 0;

	int ** forest = new int*[f_size]; // 대나무숲
	vector<index> sortedForest(f_size*f_size);
	vector<int> maxValue(f_size * f_size,0);

	for (int i = 0; i < f_size; i++)
	{
		forest[i] = new int[f_size];
		for (int j = 0; j < f_size; j++)
		{
			cin >> forest[i][j];
			// 2차원 배열의 정보를 1차원 배열에 저장
			int k = i * f_size + j;
			sortedForest[k].tree = forest[i][j];
			sortedForest[k].row = i;
			sortedForest[k].col = j;
		}
	}

	sort(sortedForest.begin(), sortedForest.end(), cmp);

	for (int i = 0; i < f_size * f_size; i++) {
		panda_max = max(panda_max, panda_road(forest, sortedForest, maxValue, i));
	}
	cout << panda_max;
}