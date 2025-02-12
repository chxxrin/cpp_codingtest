#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int occur[10] = {};

    int mul = a * b * c;

    // 계산 결과를 자릿수별로 확인하여 저장
    while (mul > 0)
    {
        occur[mul % 10]++;
        mul /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << occur[i] << '\n';
    }
}