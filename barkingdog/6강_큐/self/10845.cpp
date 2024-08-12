#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<int> Q;

    int n;
    cin >> n;

    while(n--) {
        string op;
        cin >> op;
        if(op == "push") {
            int t;
            cin >> t;
            Q.push(t);
        } else if(op == "pop") {
            if(Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        } else if(op == "size") {
            cout << Q.size() << '\n'; 
        } else if(op == "empty") {
            cout << Q.empty() << '\n';
        } else if(op == "front") {
            if(Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.front() << '\n';
            }
        } else {
            if(Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.back() << '\n';
            }
        }
    }
}