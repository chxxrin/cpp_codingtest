#include <iostream>
#include <algorithm>

using namespace std;

int n; // 정수의 개수 (배열의 크기)
int s; // 목표 합
int total; // 현재 부분 배열의 합
int a[100004]; // 정수를 저장할 배열 
int minvalue = 0x7fffffff; // 합이 s 이상인 부분 배열의 최소 길이 (초기값은 최대값으로 설정)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }    

    total = a[0]; // total배열 초기화

    // 투 포인터 탐색
    int end = 0;
    // 합이 s 이상이 되는 순간마다 최소 길이를 업데이트하고, start 포인터를 이동시켜 다음 부분 배열을 검사
    for(int start = 0; start<n;start++) {
        while(end < n && total < s) {
            end++;
            // end가 배열 끝까지 돌 때까지 total에 현재 끝값을 게속 더함
            if(end != n) {
                total += a[end];
            }
        }
            // end가 범위를 벗어나면 종룔
            if(end == n) {
                break;
            }
            minvalue = min(minvalue, end-start+1);
            total -= a[start];
        }
        if(minvalue == 0x7fffffff) {
            minvalue = 0;
        }
            cout << minvalue;
    }
