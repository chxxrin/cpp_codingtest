#include <iostream>
#include <string>

using namespace std;

string s;
int freq[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for(auto c: s) {
        freq[c - 'a']++;
    }
    
    for(int i=0;i<26;i++) {
        cout << freq[i] << ' ';
    }

}