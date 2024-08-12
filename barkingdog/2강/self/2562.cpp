#include <iostream>
#include <algorithm>
using namespace std;

int num[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 일단 수 9개를 받음
    for(int i=0;i<9;i++) {
        cin >> num[i];
    }

    cout << *max_element(num, num+9) << '\n'; // 최댓값 출력 : *max_element(처음, 끝) 해당 위치의 값을 역참조하여 최댓값을 출력
    cout << max_element(num, num+9) - num + 1; // 최댓값이 몇번째 수인지 출력 : 최댓값의 위치에서 배열의 처음 위치를 빼면 최댓값의 인덱스, 문제에서 1부터 시작하는 위치를 출력해야 하므로 1을 더함

}

// 최댓값 : *max_element(arr, arr+n)
// 최댓값의 인덱스 : max_element(arr, arr+n) - arr