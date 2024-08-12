#include <iostream>
#include <stack>

using namespace std;

int k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    stack<int> S;
    int sum=0;

    while(k--) {
        int num;
        cin >> num;
        if(num == 0) {
            S.pop();
        } else {
            S.push(num);
        }
    }

    while(!S.empty()) {
        sum += S.top();
        S.pop();
    }
    cout << sum << '\n';
}