#include <iostream>

using namespace std;

// a부터 z까지의 카운트 배열 생성
int freq[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 문자열 입력받음
    string s;
    cin >> s;

    for(auto c: s) {     // s에 있는 알파벳을
        freq[c-'a']++; // 카운트 배열에 하나씩 넣음, 'a'를 뺌으로써 index 0부터 시작하도록 함
    }
    for(int i=0;i<26;i++) {
        cout << freq[i] << ' ';
    } // 배열 출력!
}