#include <iostream>
#include <algorithm>

using namespace std;

int func2(int arr[], int N) {
    int occur[101] = {}; // 0으로 초기화된 101 크기의 배열

    for (int i = 0; i < N; i++) {
        if (occur[100 - arr[i]] == 1) { // arr[i]와 합해서 100이 되는 수가 존재하는지 확인
            return 1;
        }
        occur[arr[i]] = 1; // 현재 수를 기록
    }
    return 0; // 합해서 100이 되는 두 수가 없으면 0 반환
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cout << "Enter the number of elements in the array: ";
    cin >> N;

    int arr[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int result = func2(arr, N);
    if (result == 1) {
        cout << "There are two numbers in the array that add up to 100." << endl;
    } else {
        cout << "There are no two numbers in the array that add up to 100." << endl;
    }

    return 0;
}
