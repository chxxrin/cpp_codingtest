#include <iostream>

using namespace std;

// 각 자리 숫자의 빈도를 저장할 배열을 선언
int arr[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    int answer = 0;

    // 자리수 추출
    while(n) {
        arr[n % 10]++;
        n /= 10;
    }

    for(int i=0;i<10;i++) {
        if(i == 6 || i == 9) continue; // 별도로 처리할거니까 일단 생략
        answer = max(answer, arr[i]); // 6과 9를 제외한 나머지 숫자들 중 가장 큰 빈도를 answer에 저장
    }

    // (a[6]+a[9])/2를 올림한 값이 6, 9에 대한 필요한 세트의 수이므로 (a[6]+a[9]+1)/2을 계산
    answer = max(answer, (arr[6]+arr[9]+1)/2); // 합산된 빈도를 2로 나눈 후 올림한 값
    cout << answer;

}