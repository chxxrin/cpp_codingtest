#include <iostream>

using namespace std;

// nCk = n!/(n-k)!k!
// nPr = n!/(n-k)!
int main() { // nCk
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int k;
    cin >> n >> k;
    int result = 1;

    for(int i=1;i<=n;i++) { // n!
        result *= i;
    }
    for(int i=1;i<=k;i++) { // k!
        result /= i;
    }
    for(int i=1;i<=n-k;i++) { //(n-k)!
        result /= i;
    }
    cout << result << '\n';
}