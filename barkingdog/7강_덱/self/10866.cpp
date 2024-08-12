#include <iostream>
#include <deque>
#include <string> // string 라이브러리 포함

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<int> DQ;

    int n;
    cin >> n;

    while(n--) {
        string op;
        cin >> op;
        if(op == "push_front") {
            int x;
            cin >> x;
            DQ.push_front(x);
        } else if(op == "push_back") {
            int x;
            cin >> x;
            DQ.push_back(x);
        } else if(op == "pop_front") {
            if(DQ.empty()) {
                cout << -1 << '\n';
            } else {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        } else if(op == "pop_back") {
            if(DQ.empty()) {
                cout << -1 << '\n';
            } else {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        } else if(op == "size") {
            cout << DQ.size() << '\n';
        } else if(op == "empty") { // "empty" 명령어에 대한 조건 추가
            cout << DQ.empty() << '\n';
        } else if(op == "front") {
            if(DQ.empty()) {
                cout << -1 << '\n';
            } else {
                cout << DQ.front() << '\n';
            }
        } else if(op == "back") {
            if(DQ.empty()) {
                cout << -1 << '\n';
            } else {
                cout << DQ.back() << '\n';
            }
        }
    }

    return 0;
}
