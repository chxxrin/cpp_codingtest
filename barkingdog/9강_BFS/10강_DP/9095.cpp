#include <iostream>

using namespace std;

// d[i] = i를 1, 2, 3의 합으로 나타내는 방법의 수
int n;
int t;
int num;
int d[20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;   
    // 초기값 설정
    d[1]=1;
    d[2]=2;
    d[3]=4;
    for(int i=4;i<11;i++){ // n은 양수이며 11보다 작다.
        d[i]=d[i-1]+d[i-2]+d[i-3];
    }
    
    while(t--) {
        cin >> n;
        cout << d[n] << '\n';
    }

}

// #9095: 1,2,3 더하기
// 1. 테이블 정의하기 : d[i]=i를 1,2,3의 합으로 나타내는 방법의 수
// 2. 점화식 찾기 : d[4] = (1+1+1+1, 3+1, 2+1+1, 1+2+1), (1+1+2, 2+2), (1+3)
// (1) 3을 1,2,3의 합으로 나타내는 방법 + 1 = d[3]
// (2) 2를 1,2,3의 합으로 나타내는 방법 + 2 = d[2]
// (3) 1을 1,2,3의 합으로 나타내는 방법 + 3 = d[1]
// d[4] = d[1] + d[2] + d[3]
// d[i] = d[i-1] + d[i-2] + d[i-3]
// 3. 초기값 정하기 : d[1]=1, d[2]=2, d[3]=4