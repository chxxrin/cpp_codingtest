#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x; // 입력받을 값
    int odd = 0;
    int sum =0;
    int min = 100;

    for(int i=0;i<7;i++) {
        cin >> x; // 총 7번 숫자 입력을 받음

        // 1. 홀수 찾아서 합 구하기
        if(x % 2 != 0) { // 만약 홀수면
            odd++; // 홀수 개수를 하나 증가시키고
            sum += x; // sum에 해당 홀수를 더한다
            
            // 2. 찾은 홀수 중 최솟값 찾기 
            if(x < min) { // 만약 x가 최솟값보다 작다면
                min = x; // 해당 홀수 x를 최솟값으로 변경한다
            }
        }
    }
    if(odd) {
        cout << sum << '\n' << min;
    } else {
        cout << -1 << '\n';
    }


    
}