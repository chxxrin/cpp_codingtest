#include <iostream>
#include <algorithm>

using namespace std;

int func3(int N){
    for(int i=1;i*i<=N;i++) {
        if(i*i == N) {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

}
