#include <iostream>
#include <stack>

using namespace std;

#define X first
#define Y second
stack<pair<int, int>> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    long long ans = 0;

    while(n--) {
        int height;
        cin >> height;
        int cnt = 1;
        while(!S.empty() && S.top().X <= height) {
            ans += S.top().Y;
            if(S.top().X == height) {
                cnt += S.top().Y;
            }
            S.pop();
        }
        if(!S.empty()) {
            ans++;
        }
        S.push({height, cnt});
    }
    cout << ans;
}