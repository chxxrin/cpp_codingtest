// #10871 : X보다 작은수 
#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int x;

    cin >> n >> x;
    int* a = new int[n];

    for(int i=0;i<n;i++) {
        cin >> a[i];
    }   
    for(int i=0;i<n;i++) {
        if(a[i] < x) {
            cout << a[i] << ' ';
        }
    }
    delete[] a;
}