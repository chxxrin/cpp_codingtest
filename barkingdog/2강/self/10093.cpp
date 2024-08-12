#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력받는 두 수가 매우 크므로 long long형으로 선언
    long long a,b;
    cin >> a >> b;

    // 만약 a가 b보다 크면, swap해서 위치를 바꿔준다
    if(a > b) {
        swap(a,b);
    }
    // 만약 a와 b가 같거나, 차이가 1만 난다면, 그 사이에 있는 정수는 0개 이므로 0 출력
    if(a == b || b-a == 1) {
        cout << 0;
    } else { // 그게 아니면
        cout << b-a-1 << '\n'; // a와 b사이에 있는 수들의 개수를 출력하고
        for(long long i=a+1;i<b;i++) { // 사이에 있는 수들을 각각 출력!
            cout << i << ' ';
        }
    }

}