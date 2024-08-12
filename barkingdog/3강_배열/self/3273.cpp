#include <iostream>

using namespace std;

int arr[1000005];
bool occur[2000001];
int n;
int x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int answer = 0;
    
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    cin >> x;
    
    for(int i=0;i<n;i++) { // 목표 합 x에서 현재 숫자 arr[i]를 뺀 값이 0보다 큰지 확인, x - arr[i]가 배열 arr에 이미 존재했는지를 확인
        if(x-arr[i] > 0 && occur[x-arr[i]] == true) answer++;
        occur[arr[i]] = true;
    }
    cout << answer;
}