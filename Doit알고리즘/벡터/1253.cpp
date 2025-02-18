// 좋은수구하기 : 투포인터
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> A(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    // 1. 오름차순정렬
    sort(A.begin(), A.end());

    int result = 0; // 좋은수 갯수를 저장할 변수

    // 2. 이동하면서 탐색
    // 먼저 target숫자인 k를 n번 선정함!!
    for (int k = 0; k < n; k++)
    {
        long find = A[k]; // 좋은수인지 아닌지 판별할것! 즉 타겟값이 A[k]

        int i = 0;     // 시작인덱스
        int j = n - 1; // 종료인덱스

        // 투포인터 알고리즘
        while (i < j)
        {
            if (A[i] + A[j] == find)
            {
                if (i != k && j != k)
                { // A[i], A[j]가 둘다 k가 아닐때만 좋은수이므로 result++
                    result++;
                    break;
                }
                // 둘중에 하나가 k라면 그 숫자를 ++해서 이동시켜줌
                else if (i == k)
                {
                    i++; // 오른쪽으로 한 칸 이동
                }
                else if (j == k)
                {
                    j--; // 왼쪽으로 한 칸 이동
                }
            }
            else if (A[i] + A[j] < find)
            {
                i++; // 오른쪽으로 한 칸 이동
            }
            else if (A[i] + A[j] > find)
            {
                j--; // 왼쪽으로 한 칸 이동
            }
        }
    }
    cout << result << endl;
}