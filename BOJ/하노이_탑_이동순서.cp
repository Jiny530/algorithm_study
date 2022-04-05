#include <iostream>
using namespace std;

void hanoi(int n, int now, int toward, int empty)
{
    if (n == 1) printf("%d %d\n", now, toward);
    else {
        hanoi(n - 1, now, empty, toward); // 위에 쌓인 원판을 잉여자리로 이동
        printf("%d %d\n", now, toward); // 맨 밑 원판을 목표 위치로 이동
        hanoi(n - 1, empty, toward, now); // 나머지 원판을 목표위치로 이동
    }
}

int main()
{
    int N, answer=1;
    cin >> N;

    for (int i = 1; i < N; i++) answer = 2 * answer + 1;
    
    cout << answer << endl;
    hanoi(N, 1, 3, 2);

}