#include <iostream>

using namespace std;

int main() {
    
    int a = 13;
    int b = 4;

    cout << a+b << '\n';
    cout << a-b << '\n';
    cout << a*b << '\n';
    cout << a/b << '\n';
    cout << a%b << '\n';
    cout << -a << '\n';

    cout << (a==b) << '\n';
    cout << (a != b) << '\n';
    cout << (a > b) << '\n';
    cout << (a < b) << '\n';
    cout << (a >= b) << '\n';
    cout << (a <= b) << '\n';

    cout << (a & b) << '\n';
    cout << (a | b) << '\n';

    double d = 2.5;
    float f = 1.5f;

    cout << sizeof(d) << '\n';
    cout << sizeof(f) << '\n';
    cout << d << ' ' << f << '\n';
    cout << d+f << '\n';
    cout << d-f << '\n';
    cout << d*f << '\n';
    cout << d/f << '\n';

    int i2 = 65;
    float f2 = 5.2f;

    double d2 = i2+f2;
    cout << d2 << '\n';
    cout << static_cast<int>(d2) << '\n';
    cout << static_cast<char>(i2) << '\n';
    return 0;

}