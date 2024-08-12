#include <iostream>
#include <algorithm>

using namespace std;

long long n;
long long t[1500005];
long long p[1500005];
long long d[1500005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> t[i] >> p[i];
    }
    
    for(int i=n;i>=1;i--) {
        if(t[i] + i <= n+1) {
            d[i] = max(d[t[i]+i]+p[i], d[i+1]);
        }
        else d[i] = d[i+1];
    }
    cout << *max_element(d+1, d+1+n);
}