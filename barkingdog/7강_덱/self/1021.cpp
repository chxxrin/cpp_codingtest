#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<int> DQ;

    int n, m;
    cin >> n >> m;

    for(int i=1;i<=n;i++) {
        DQ.push_back(i);
    }

    int ans = 0;

    while(m--) {
        int t;
        cin >> t;
        int idx = find(DQ.begin(), DQ.end(), t) - DQ.begin(); // 목표 숫자의 인덱스를 찾습니다.

        while(DQ.front() != t) { // 덱의 앞쪽이 목표 숫자가 될 때까지 반복
            if(idx < DQ.size() - idx){ // 목표 숫자가 덱의 앞쪽 절반에 위치해 있는 경우:
                DQ.push_back(DQ.front());
                DQ.pop_front();
            } else { // 목표 숫자가 덱의 뒤쪽 절반에 위치해 있는 경우
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
            ans++;
        }
        DQ.pop_front(); // 목표 숫자가 덱의 앞쪽이 되면 이를 제거
    }
    cout << ans;
}