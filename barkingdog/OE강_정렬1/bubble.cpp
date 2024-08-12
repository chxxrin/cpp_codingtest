#include <iostream>

using namespace std;

// bubble sort : O(N^2)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[5] = {-2, 2, 4, 6, 13};
    int n=5;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1-i;j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}