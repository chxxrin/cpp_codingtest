#include <iostream>

using namespace std;

int n;
int t;
int d[20]; // d[i] = i를 1, 2, 3의 합으로 나타내는 방법의 수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 우선 d[] 배열 채우기! 방법의 수 일단 채워
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i=4;i<11;i++) {
        d[i] = d[i-1]+d[i-2]+d[i-3];
    }

    //입력받고, 테스트케이스만큼 돌려서 출력
    cin >> t;
    while(t--) {
        cin >> n;
        cout << d[n] << '\n';
    }
     
}