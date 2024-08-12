#include <iostream>

using namespace std;

int n, m;

int result;

int main() {
    int count = 0;
    cin >> n >> m;

    int a[n+1];

    for (int i=0;i<n;i++) {
        cin >> a[i];
    }

    for (int i=0; i<n; i++) {
        for (int j=0;j<n;j++) {
            result += a[i];

            if (result == m) {
                count++;
                result == 0;
                break;
            }
        }
        if(result != 0) {
            result =0;
        }
    }
    cout << count;
}