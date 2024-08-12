#include <iostream>
#include <algorithm>

using namespace std;

// card 배열을 만듦
int card[21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // card배열에 1부터 20까지 차례대로 입력
    for(int i=1;i<=20;i++) {
        card[i] = i;
    } 

    // a,b 를 10번 입력!
    for(int i=1;i<=10;i++) {
        int a,b;
        cin >> a >> b;
        reverse(card+a, card+b+1); // a부터 b까지를 역순으로 정렬
    }

    // 역순 정렬된 card배열을 차례대로 모두 출력
    for(int i=1;i<=20;i++) {
        cout << card[i] << ' ';
    }


}