#include <iostream>
#include <algorithm>

using namespace std;

int n, x;
int a[10010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    for(int i=0;i<n;i++) {
        if(a[i] < x) {
            cout << a[i] << ' ';
        }
    }
}