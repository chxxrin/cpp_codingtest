#include <iostream>
#include <algorithm>
using namespace std;

int n;
int r[1002], g[1002], b[1002];
int d[1002][3]; // 최솟값을 저장, rgb를 각각 저장

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> r[i] >> g[i] >> b[i];
    }

    d[1][0] = r[1];
    d[1][1] = g[1];
    d[1][2] = b[1];

    for(int i=2;i<=n;i++) {
        d[i][0] = min(d[i-1][1], d[i-1][2]) + r[i];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + g[i];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + b[i];
    }

    cout << *min_element(d[n], d[n]+3) << '\n';


}