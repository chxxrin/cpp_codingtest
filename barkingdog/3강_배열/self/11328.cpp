#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; // 테스트 케이스 수 
    cin >> n;

    while(n--) {
        int cnt[26] = {}; // 각 문자의 개수를 저장하는 배열
        string s1, s2;
        cin >> s1 >> s2;

        for(auto c: s1) { // 첫 번째 문자열의 각 문자는 개수+1
            cnt[c-'a']++;
        }

        for(auto c: s2) { // 두 번째 문자열의 각 문자는 개수-1
            cnt[c-'a']--; 
        }

        // 0이 아닌 배열의 요소가 있을 경우, 개수가 다른 문자가 존재하므로 false
        bool isPossible = true;
        for(int i: cnt) {
            if(i != 0) {
                isPossible = false;
            }
        }
        if(isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
    }

}