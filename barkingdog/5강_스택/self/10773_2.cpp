#include <iostream>
#include <stack>
using namespace std;

int k;
int answer = 0;
stack<int> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;

    while(k--) {
        int n;
        cin >> n;
        if(n==0) {
            S.pop();
        } else {
            S.push(n);
        }
    }

    while(!S.empty()) {
        answer += S.top();
        S.pop();
    }
    cout << answer;

}