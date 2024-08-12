#include <iostream>

using namespace std;

// a부터 z까지의 개수를 셀 빈 배열
// 배열을 전역변수에 선언하면 자동으로 0으로 초기화가 된다
// 만약 지역변수로 선언하면 int freq[26]={}, fill(freq,freq+26,0) 과 같은 처리를 해야함
int freq[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    // 입력받은 문자열 s의 각 문자를 순회하며, 각 문자의 빈도를 freq 배열에 저장
    // c - 'a'는 문자를 'a'부터 0, 1, 2, ..., 25로 변환하는 역할을 합니다. 예를 들어, 'a'는 0, 'b'는 1, ..., 'z'는 25가 됩니다.
    for(auto c: s) { // auto : 변수의 타입을 자동으로 추론
        freq[c -'a']++; // freq[c - 'a']++를 통해 해당 문자의 빈도를 1씩 증가
    }
    // freq 배열의 모든 원소를 순회하며, 각 알파벳의 빈도를 출력
    for(int i=0;i<26;i++){
        cout << freq[i] << ' '; // 각 알파벳 빈도를 공백으로 구분하여 출력
    }

}