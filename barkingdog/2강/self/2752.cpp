#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 배열 하나 생성
    int arr[4];
    for(int i=0;i<3;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+3);

    for(int i=0;i<3;i++) {
        cout << arr[i] << " ";
    }
}