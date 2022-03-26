#include <iostream>
using namespace std;

int self_number(int n) {
    
    int sum = n;

    while (n != 0) {
        sum += n % 10;
        n = n / 10;
    }

    return sum;
}


int main() {

    int num[10001];
    fill_n(num, 10001, 1);
    
    int self = 0;
    for (int i = 1; i <= 10000; i++) {
        self = self_number(i);
        if (self <= 10000) num[self] = 0;
    }

    for (int i = 1; i <= 10000; i++) {
        if (num[i]) cout << i << endl;
    }
}