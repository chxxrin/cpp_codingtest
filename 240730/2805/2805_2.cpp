#include <iostream>
#include <vector>

using namespace std;

int N; // 나무의 수
int M; // 가져가려고 하는 나무의 길이
int tree[1000000];

// h 높이의 톱으로 나무를 자를때 얻게 되는 나무의 양 구하기
long long cut(int h) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (tree[i] > h) {
            sum += tree[i] - h;
        }
    }
    return sum;
}

// 이분탐색
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    int low = 0;
    int high = *max_element(tree, tree + N); // 가장 높은 나무의 높이로 high 설정
    int answer = 0; // 초기 답변 값을 0으로 설정

    // 범위를 벗어나지 않으면 계속 값을 찾는다
    while (low <= high) {
        int mid = (low + high) / 2; // 이분탐색
        long long tmp = cut(mid); // 범위의 중간 값으로 톱을 사용해본다

        if (tmp >= M) {
            answer = mid; // 조건을 만족하면 answer를 업데이트
            low = mid + 1; // 더 높은 값을 탐색
        } else {
            high = mid - 1; // 더 낮은 값을 탐색
        }
    }
    
    cout << answer << endl; // 최종 답변을 출력
    return 0;
}
