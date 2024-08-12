#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt[10]; // 0~9까지 개수를 셀 배열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    int a, b, c;
    cin >> a >> b >> c;

    int result = a*b*c;
    while(result > 0) { // result가 0이 될 때까지 반복하여 모든 자리수를 처리
        cnt[result % 10]++; // result의 마지막 자리수(일의 자리)를 result % 10로 구하여 cnt 배열의 해당 인덱스 값을 증가
        result /= 10; // result를 10으로 나눠 마지막 자리수를 제거, 이렇게 하면 다음 자리수가 새로운 마지막 자리수가 됨!
    }

    // 출력
    for(int i=0;i<10;i++) {
        cout << cnt[i] << '\n';
    }

}