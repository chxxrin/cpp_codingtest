#include <iostream>
#include <algorithm>

using namespace std;

// 최댓값, 최솟값을 구하는 문제가 나오면
// 1. 배열생성 후 배열에 for문으로 입력받음
// 2. sort(arr, arr+n) 해서 오름차순 정렬
// 3. 이제 오름차순 정렬되어 있으니 원하는대로 뽑아서 사용!

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[3];
    for(int i=0;i<3;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+3);

    // (a,b,c) 에서 a==b==c -> a==c만 검증하면 됨
    if(arr[0] == arr[2]) {
        cout << 10000 + arr[2]*1000;
    } else if(arr[0] == arr[1] || arr[1] == arr[2]) {
        cout << 1000 + arr[1]*100;
    } else {
        cout << arr[2]*100;
    }
}