#include <iostream>

using namespace std;

int func2(int arr[], int N)
{
    int occur[101] = {}; // 각 수의 등장여부를 카운트하는 배열

    for (int i = 0; i < N; i++)
    {
        if (occur[100 - arr[i]])
            return 1;
        occur[arr[i]] = 1;
    }
    return 0;
}