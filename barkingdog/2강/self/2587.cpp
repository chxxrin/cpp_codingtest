#include <iostream>
#include <algorithm>

using namespace std;

int arr[5];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int sum=0; // 1. 평균에 사용할 입력한 5개의 수들의 합
    for(int i=0;i<5;i++) {
        cin >> arr[i]; // 5개의 수를 입력받음
        sum += arr[i]; // 입력받은 수들을 모두 합해서 sum에 저장
    }

    sort(arr, arr+5); // 2. 중앙값에 사용할 정렬 수행!

    cout << sum/5 << '\n';
    cout << arr[2] << '\n'; // 그 중 가운데 값 arr[2]이 중앙값!
}