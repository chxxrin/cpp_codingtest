#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; // 방번호
    cin >> n;

    int a[10] = {}; // 0~9까지의 숫자 개수를 저장하는 배열, a[i]는 숫자 i가 등장한 횟수를 저장
    int answer = 0; // 필요한 숫자 세트의 최소 개수

    // 자리수 호출
    while (n > 0)
    {
        a[n % 10]++; // n의 마지막 자리 숫자를 배열 a에 카운트
        n /= 10;     // n을 10으로 나누어 자리수를 이동
    }

    // 0~9 중에서 6과 9를 제외한 숫자 중에서 가장 많이 필요한 개수를 찾습니다
    for (int i = 0; i < 10; i++)
    {
        if (i == 6 || i == 9)
            continue;
        answer = max(answer, a[i]);
    }

    // (a[6]+a[9])/2를 올림한 값이 6, 9에 대한 필요한 세트의 수이므로 (a[6]+a[9]+1)/2을 계산
    answer = max(answer, (a[6] + a[9] + 1) / 2);

    cout << answer;

    return 0;
}