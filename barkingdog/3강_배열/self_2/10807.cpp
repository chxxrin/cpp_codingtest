#include <iostream>

using namespace std;

int n, v;
int a[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    cin >> v;

    int cnt=0;
    for(int i=0;i<n;i++) {
        if(v == a[i]) cnt++;
    }
    cout << cnt;

}