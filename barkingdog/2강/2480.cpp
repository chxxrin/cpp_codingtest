#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;


// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
    
//     int a, b, c;
//     cin >> a >> b >> c;

//     if(a == b == c) {
//         cout << 100000 + a*1000;
//     } else if(a==b || a==c) {
//         cout << 1000+ a*100;
//     } else if(b==c) {
//         cout << 1000 + b*100;
//     } else {
//         cout << max({a,b,c}) * 100;
//     }
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    sort(a, a+3);

    if(a[0] == a[2]) {
        cout << 10000 + a[0]*1000; // 정렬했으니 첫번째 수와 세번째 수가 같으면 이건 세 수가 모두 같은 것
    } else if(a[0] == a[1] || a[1] == a[2]) {
        cout << 1000 + a[1]*100; // 두 수가 동일
    } else {
        cout << a[2]*100;
    }

}