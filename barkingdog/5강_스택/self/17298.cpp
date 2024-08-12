#include <iostream>
#include <stack>
using namespace std;

int a[1000005];
int ans[1000005];
stack<int> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    // 역순으로 처리
    for(int i=n-1;i>=0;i--) {
        while(!S.empty() && S.top() <= a[i]) {  // 스택의 최상단에 있는 값이 현재 값 a[i]보다 작거나 같으면 스택에서 제거
            S.pop();
        }
        if(S.empty()) { // 스택이 비어있으면 a[i]보다 큰 값이 오른쪽에 없다는 의미
            ans[i] = -1;
        } else { // 스택의 최상단 값이 a[i]보다 크므로 그 값을 결과로 저장
            ans[i] = S.top();
        }
        S.push(a[i]);
    }
    for(int i=0;i<n;i++) {
        cout << ans[i] << ' ';
    }
}