// LCS2
#include <iostream>
#include <cstring>
using namespace std;

char str1[1001], str2[1001];
int cache[1010][1010];
int ans;

int getmax(int a, int b) { 
    return a > b ? a : b; 
}

int dp(int i, int j) {
    if (i < 0 || j < 0) {
        return 0;
    }
    if (cache[i][j] != -1) {
        return cache[i][j];
    }
    if (str1[i] == str2[j]) {
        return cache[i][j] =  1 + dp(i - 1, j - 1); 
    }
    else {
        return cache[i][j] = getmax(dp(i-1,j), dp(i, j - 1));
    }
}

void print2(int i, int j) {
    if (i < 0 || j < 0) {
        return;
    }

    if (str1[i] == str2[j]) {
        print2(i - 1, j - 1);
        cout << str1[i];
    }
    else {
        if (i == 0) {
            print2(i, j - 1);
        }
        else if (j == 0) {
            print2(i - 1, j);
        }
        else if (cache[i - 1][j] > cache[i][j - 1]) {
            print2(i - 1, j);
        }
        else {
            print2(i, j - 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str1 >> str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i = 0; i < 1010; i++) {
        for (int j = 0; j < 1010; j++) {
            cache[i][j] = -1;
        }
    }

    cout << dp(len1-1, len2-1) << '\n';
    print2(len1 - 1, len2 - 1);
}