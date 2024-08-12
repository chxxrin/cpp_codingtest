#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int e,f;
    e = (a*d + b*c);
    f = b*d;
    int g = gcd(e,f);
    cout << e/g << ' ' << f/g;
    return 0;
}