#include <iostream>
#include <stack>

using namespace std;

stack<int> S;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int cnt = 1; //스택에 넣을 숫자를 순서대로 증가시키기 위한 변수
    string ans; // "+"와 "-"를 저장하여 나중에 한 번에 출력할 문자열

    while(n--) {
        int t;
        cin >> t;

        while(cnt <= t) {
            S.push(cnt++);
            ans += "+\n";
        }
        if(S.top() != t) {
            cout << "NO\n";
            return 0;
        }
        S.pop();
        ans += "-\n";
    }
    cout << ans;
}