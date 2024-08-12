#include <iostream>

using namespace std;

int n;
int s[305];
int d[305];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int tot = 0;
    for(int i=1;i<=n;i++) {
        cin >> s[i];
        tot += s[i];
    }
    
    if(n <= 2) {
        cout << tot;
        return 0;
    }

    // 초기값 설정
    d[1]=s[1];
    d[2]=s[2];
    d[3]=s[3];

    for(int i=4;i<=n-1;i++) {
        d[i]=min(d[i-2],d[i-3]) + s[i];
    }
    cout << tot - min(d[n-1],d[n-2]);
}

// 1. 테이블 정의하기 : d[i] = i번째 계단까지 올라섰을 때 밟지 않을 계단의 합의 최솟값, 단 i번째 계단은 반드시 밟지 않을 계단으로 선택해야함
// 2. 점화식 찾기 : 직접 테이블 그리기 
// d[1]=s[1], d[2]=s[2], d[3]=s[3], d[4] = d[1]+s[4], d[5] = d[3]+s[5]
// d[k] = min(d[k-2], d[k-3]) + s[k]