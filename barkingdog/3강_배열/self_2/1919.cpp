#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int answer = 0;
    int cnt[2][26] = {};
    for(auto c: s1) {
        cnt[0][c-'a']++;    
    }
    for(auto c:s2) {
        cnt[1][c-'a']++;
    }

    for(int i=0;i<26;i++) {
        answer += abs(cnt[0][i]-cnt[1][i]);
    }
    cout << answer;
}
