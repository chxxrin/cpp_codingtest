// 에라토스테네스의 체를 사용하여 주어진 범위 내의 모든 소수를 찾는 프로그램

#include <iostream>
#include <vector>
using namespace std;

// 소수 여부를 저장하는 벡터, 처음에는 모든 수를 소수로 가정
vector<bool> state(1000001, true);

// 에라토스테네스의 체 함수
void sieve(int n ) {
    state[1] = false; // 1은 소수가 아니므로 false로 설정
    for(int i=2;i*i<=n;i++) { // 2부터 sqrt(n)까지 반복
        if(!state[i]) continue; // 이미 소수가 아닌 것으로 판명된 경우 건너뜀
        for(int j=i*i;j<=n;j+=i) { // i의 배수들을 모두 소수가 아닌 것으로 표시
            state[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m,n;
    cin >> m >> n;
    sieve(n); // n까지의 소수를 찾기 위해 에라토스테네스의 체를 수행

    for(int i=m;i<=n;i++) {
        if(state[i]) { // i가 소수인 경우 출력
            cout << i << '\n';
        }
    }
}