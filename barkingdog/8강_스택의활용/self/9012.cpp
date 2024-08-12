#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string a;
        cin >> a;    
        stack<char> S;
        bool isValid = true;

        for(auto c: a) {
            if(c == '(') {
                S.push(c);
            } else if (c == ')') {
                if(S.empty() || S.top() != '(') {
                    isValid = false;
                    break;
                }
                S.pop();
            }
        }
        if(!S.empty()) {
            isValid = false;
        }
        if(isValid) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}