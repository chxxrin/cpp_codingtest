#include <iostream>

using namespace std;

int N; // 수열의 개수
int M; // 수열의 합

// 투 포인터(슬라이딩 윈도우) 알고리

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int A[N+1]; // 수열을 저장하는 배열

    // 수열 입력
    for (int i=0;i<N;i++) {
        cin >> A[i];
    }

    int start=0; //슬라이딩 윈도우의 시작 지점
    int end=0; //슬라이딩 윈도우의 끝 지점
    int result = A[0]; // 현재 슬라이딩 윈도우의 합
    int count = 0; //합이 M이 되는 부분 수열의 개수

    // 슬라이딩 윈도우 알고리즘
    while(start <= end && end < N) { 
        if(result < M) { // 합이 M보다 작을 때
            result += A[++end]; // 윈도우의 끝을 오른쪽으로 이동(++end)하여 result에 새로운 요소를 더함
        } else if(result == M) {  // 합이 M과 같을 때 
            count++; // 부분 수열의 개수를 증가
            result += A[++end]; // 윈도우의 끝을 오른쪽으로 이동하여 result에 새로운 요소를 더함
        } else if(result > M) { // 합이 M보다 클 때 result에서 시작 요소를 뺍니다. 
            result -= A[start++]; // 윈도우의 시작을 오른쪽으로 이동(start++)하여

            if(start>end) { // 만약 start가 end를 넘어가면  
                end=start; // end를 start에 맞추고,
                result=A[start]; // result를 새로운 시작 값으로 설정
            }
        }
    }
    cout << count; // 합이 M이 되는 부분 수열의 개수를 출력

}
