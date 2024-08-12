#include <iostream>
#include <algorithm>

using namespace std;

int n;
int cnt[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int answer = 0;

    while(n) {
        cnt[n % 10]++;
        n /= 10;
    }

    for(int i=0;i<10;i++) {
        if(i == 6 || i == 9) continue;
        answer = max(answer, cnt[i]);
    }

    answer = max(answer, (cnt[6]+cnt[9]+1)/2);
    cout << answer;

}