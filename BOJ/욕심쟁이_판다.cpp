#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct index
{
	int tree;
	int row;
	int col;
	int max;
};

bool cmp(const index& a, const index& b)
{
	return a.tree < b.tree;
}
int f_size;
int panda_road(int** forest, vector<index> &info, int curr) 
{
	int r = info[curr].row;
	int c = info[curr].col;
	int max_road = 0;
	cout << r << c << info[curr].tree << endl;
	// row=r-1이고 col=c인 것을 찾아야 ㅏ...
	// 상하좌우에 더 작은 숲이 있으면 그 숲의 최대 길찾기 값 +1
	if (r > 0 && forest[r - 1][c] < info[curr].tree) {
		max_road = max(max_road, info[curr-f_size].max + 1); // 상
		cout << curr << "         1" << endl;
	}
	if (r < f_size - 1 && forest[r + 1][c] < info[curr].tree) {
		max_road = max(max_road, info[curr + f_size].max + 1); // 하
		cout << curr << "         2" << endl;
	}
	if (c > 0 && forest[r][c - 1] < info[curr].tree) {
		max_road = max(max_road, info[curr - 1].max + 1); // 좌
		cout << curr << "         3" << endl;
	}
	if (c < f_size && forest[r][c + 1] < info[curr].tree) {
		max_road = max(max_road, info[curr + 1].max + 1); // 우
		cout << curr << "         4" << endl;
	}

	// 주변에 더 작은 숲이 없으면 1 반환
	if (max_road == 0) info[curr].max = 1;
	else info[curr].max = max_road;

	return info[curr].max;
	
}
int main() {

	cin >> f_size;
	int panda_max = 0;

	int ** forest = new int*[f_size]; // 대나무숲
	vector<index> forestInfo(f_size*f_size);

	for (int i = 0; i < f_size; i++)
	{
		forest[i] = new int[f_size];
		for (int j = 0; j < f_size; j++)
		{
			cin >> forest[i][j];
			// 2차원 배열의 정보를 1차원 배열에 저장
			forestInfo[i * f_size + j].tree = forest[i][j];
			forestInfo[i * f_size + j].row = i;
			forestInfo[i * f_size + j].col = j;
			forestInfo[i * f_size + j].max = 0;

			cout << forestInfo[i * f_size + j].tree << " " << forestInfo[i * f_size + j].row << endl;
		}
	}

	sort(forestInfo.begin(), forestInfo.end(), cmp);

	for (int i = 0; i < f_size * f_size; i++) {
//		cout << forestInfo[i].tree << endl;
		panda_max = max(panda_max, panda_road(forest, forestInfo, i));
	}
	
	cout << panda_max;
}