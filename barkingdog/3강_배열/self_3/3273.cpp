// 두 수의 합이 특정 값 X가 되는 쌍의 개수

#include <iostream>

using namespace std;

int a[1000001] = {}; // 최대 1,000,000개의 자연수를 저장할 배열
bool occur[2000001]; // 특정 숫자가 등장했는지 저장하는 배열, x - a[i] 값이 1000000보다 커지는 경우를 예외 처리하는 게 번거롭기 때문에 배열을 2,000,000까지 잡아줍니다.
int n, x;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> x;

    // 배열을 순회하며 합이 X가 되는 쌍 찾기
    for (int i = 0; i < n; i++)
    {
        // x-a[i]가 존재하는지 확인, 이미 등장한 수인지 확인
        if (x - a[i] > 0 && occur[x - a[i]])
        {
            answer++; // x - a[i]가 이전에 등장한 수라면, a[i]와 함께 합이 x가 되는 쌍을 찾은 것
        }
        occur[a[i]] = true; // a[i]를 occur 배열에 true로 표시하여 방금 등장한 숫자를 기록
    }

    cout << answer;
}