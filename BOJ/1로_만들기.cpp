#include <vector>
#include <iostream>
using namespase std;
int main() {
	int x;
	cin >> x;
    if (x==1) cout << 0;
	else if (x <= 3) cout << 1;
	else {
        vector<int> answer(x+1,0);
		answer[1] = answer[2] = answer[3] = 1; //3까지의 최소값은 1

		for (int i = 4; i <= x; i++) {
			// 각 숫자의 최소값을 업데이트
            
            answer[i] = answer[i - 1] + 1;
			//각각 3으로 나눈 경우와 2로 나눈 경우와 1로 뺀 경우 중 더 작은 값으로 교체
			if (i % 3 == 0) answer[i] = answer[i] < answer[i / 3] + 1 ? answer[i] : answer[i / 3] + 1;
			if (i % 2 == 0) answer[i] = answer[i] < answer[i / 2] + 1 ? answer[i] : answer[i / 2] + 1;
			
		}

		cout << answer[x];
	}



}