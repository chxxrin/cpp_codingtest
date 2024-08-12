#include <iostream>
#include <algorithm>

using namespace std;

int solution2(int arr[]) {
    int max = arr[0];

    for(int i=0;i<=3;i++){
        if(arr[i] > max) {
            mx = arr[i];
        }
    }
    return max;
}

int solution3(int arr[]) {
    return *max_element(arr, arr+4);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solution2();
}

