// #10871 : X보다 작은수 
#include <iostream>

using namespace std;

int n; // 정수의 개수
int x; // 주어진 정수
int a[10005]; // 수열(크기가 10000이하이므로 최대 10005로 정함)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
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