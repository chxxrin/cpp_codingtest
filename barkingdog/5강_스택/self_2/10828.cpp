#include <iostream>
#include <stack>

using namespace std;

int n;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    stack<int> S;
    while(n--) {
        string op;
        cin >> op;
        if(op == "push") {
            int x;
            cin >> x;
            S.push(x);
        } else if(op == "pop") {
            if(S.empty()) {
                cout << -1 << '\n';
            } else {
                cout << S.top() << '\n';
                S.pop();
            }
        } else if(op == "size") {
            cout << S.size() << '\n';
        } else if(op == "empty") {
            cout << S.empty() << '\n';
        } else {
            if(S.empty()) {
                cout << -1 << '\n';
            } else {
                cout << S.top() << '\n';
            }
        }
    }
}