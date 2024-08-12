#include <iostream>
#include <cstring>
using namespace std;

char str1[4001];
char str2[4001];
int cache[4010][4010];
int ans;

int dp(int i, int j) {
    if (str1[i] == str2[j]) {
        return 1 + dp(i - 1, j - 1);   
    }
    else {
        return 0;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str1 >> str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i = 0; i < len1 ; i++) {
        for (int j = 0; j < len2; j++) {
            int res = dp(i, j);
            if (res > ans) {
                ans = res;
            }
        }
    }
    cout << ans << '\n';
}