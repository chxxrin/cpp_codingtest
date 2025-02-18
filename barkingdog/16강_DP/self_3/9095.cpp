// 1. 테이블 정의하기 : d[i]=i를 1,2,3의 합으로 나타내는 방법의 수
// 2. 점화식 찾기 : d[i] = d[i-1] + d[i-2] + d[i-3]

#include <iostream>

using namespace std;

int d[20]; // d[i] = i를 1, 2, 3의 합으로 나타내는 방법의 수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 초기값 정하기
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    // 점화식 계산
    for (int i = 4; i < 11; i++)
    {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }

    // 입력
    int t;
    cin >> t;
    // 출력
    while (t--)
    {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}