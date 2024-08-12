#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    // 이거는 문자열을 a부터 z까지 총 26번을 모두 돌아야 한다
    for(char a='a' ; a<='z';a++){
        int cnt = 0;
        for (auto c: s){
            if(a==c) {
                cnt++;
            }
        }
        cout << cnt << ' ';
    }

}