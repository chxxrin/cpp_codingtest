#include <iostream>
#include <algorithm>

using namespace std;

int func1(int N){
    int sum = 0;
    for (int i=1;i<=N;i++) {
        if(i % 3 == 0 || i % 5 == 0){
            sum += i;
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num;
    cin >> num;
    cout << func1(num);
}