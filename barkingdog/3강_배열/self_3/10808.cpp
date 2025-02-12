#include <iostream>

using namespace std;

// a~z까지의 알파벳을 저장할 배열
// 전역에 선언하면 자동으로 0으로 채워짐
int freq[26];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for (auto c : s)
        freq[c - 'a']++;
    for (int i = 0; i < 26; i++)
        cout << freq[i] << ' ';
}

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     string s;
//     cin >> s;
//     for (char a = 'a'; a <= 'z'; a++)
//     {
//         int cnt = 0;
//         for (auto c : s)
//             if (a == c)
//                 cnt++;
//         cout << cnt << ' ';
//     }
// }
