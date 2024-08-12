#include <iostream>

using namespace std;

int arr[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int answer = 0;

    while(n) {
        arr[n % 10]++;
        n /= 10;
    }

    for(int i=0;i<10;i++) {
        if(i == 6 || i == 9) continue;
        answer = max(answer, arr[i]);
    }

    answer = max(answer, (arr[6]+arr[9]+1)/2);
    cout << answer;
}