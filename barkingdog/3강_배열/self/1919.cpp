#include <iostream>

using namespace std;

int arr[2][26];
// arr[0][26] : 첫 번째 문자열의 문자의 출현 횟수를 저장
// arr[1][26] : 두 번째 문자열의 문자의 출현 횟수를 저


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s1, s2;
    cin >> s1 >> s2;

    int cnt = 0;
    
    for(auto c: s1) {
        arr[0][c-'a']++;
    }
    for(auto c: s2) {
        arr[1][c-'a']++;
    }

    for(int i=0;i<26;i++) {
        cnt += abs(arr[0][i]-arr[1][i]);
    }
    cout << cnt;
}