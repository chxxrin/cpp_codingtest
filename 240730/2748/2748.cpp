#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// 너무 느린 코드!!!

int fibo (int num) {
    int result;

    if (num < 2) {
        return num;
    } else {
        return (fibo(num-1) + fibo(num-2));
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", fibo(n));
}
