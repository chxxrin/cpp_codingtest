#include <iostream>

using namespace std;

void solution(int n) {
    int count = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            count++;
        }
    }

    for(int i=0;i<n;i++) {
        count++;
    }

    for(int i=0;i<2*n;i++) {
        count++;
    }

    for(int i=0;i<5;i++) {
        count++;
    }
    cout << count << '\n';
}

int main() {
    solution(6);
    return 0;
}