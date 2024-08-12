#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) { // 별 몇 줄?
        for(int j=0;j<=i;j++) { // 한 줄에 별 몇 개?
            cout << '*';
        }
        cout << '\n';
    }
}