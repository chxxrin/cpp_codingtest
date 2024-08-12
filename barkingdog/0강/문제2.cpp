#include <iostream>
#include <algorithm>

using namespace std;


int func2(int arr[], int N) {
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            if(arr[i] + arr[j] == 100) {
                return 1;
            }
        }
    } return 0;
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