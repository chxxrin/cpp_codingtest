#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    stack<int> S;

    long long height;
    long long ans;
    
    while(n--) {
        cin >> height;
        while(!S.empty() && S.top() <= height) {
            S.pop();
        }
        ans += S.size();
        S.push(height);
    }
    cout << ans;
    return 0;
}