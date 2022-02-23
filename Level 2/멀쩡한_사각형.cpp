using namespace std;

long long solution(int w,int h) {
    long long answer = 0;

    // 원점을 지나는 y = H/W * x 
    // 위 식에 1에서 W-1까지 대입해서 나오는 값보다 작거나 같은 자연수를 구한다
    double equation;
    for (int i=1; i<w; i++){
        equation = (double)h * i / w;
        answer += (int)equation;
    }

    return answer*2;
}