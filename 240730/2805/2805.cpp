#include <cstdio>


using namespace std;

int N; // 나무의 수
int M; // 가져가려고 하는 나무의 길이
int tree[1000000];

// h 높이의 톱으로 나무를 자를때 얻게 되는 나무의 양 구하기
long long cut(int h) {
    long long sum = 0;
    for (int i=0;i<N;i++) {
        if (tree[i] > h){
            sum += tree[i] - h;
        }
        // 중간에 이미 sum이 목표치를 넘어간다면?
    }
    return sum;
}

// 이분탐색
int main() {
    scanf("%d%d", &N, &M);

    for (int i=0;i<N;i++){
        scanf("%d", &tree[i]);
    }
    // 0 ~ 1000000000 범위에서 톱을 사용해본다
    // 하나씩 하면 시간이 오래 걸릴테니 반씩 알아본다
    // low ~ high 범위에 있다고 가정하고, 적절한 값을 찾는다
    int low = 0;
    int high = 1000000000;
    int mid;
    int answer = 0;


    // 범위를 벗어나지 않으면 계속 값을 찾는다
    while (low <= high) {
        mid = (low + high) / 2; // 이분탐색, 이 때 int의 범위를 벗어날까?
        long long tmp = cut(mid); // 범위의 중간 값으로 톱을 사용해본다
        // 딱 알맞은 나무를 얻었으면?
        if(tmp == M) {
            printf("%d\n", mid);
            return 0;
        }

        // binary search !
        // 만약 target값이 A[start] 보다 크면 end = mid-1, 
        // tartget값이 A[end] 보다 작으면 start = mid + 1
        // 나무가 부족하면 ? => 톱을 낮춘다
        else if (tmp < M) {
            high = mid -1;
        } else {
            // 나무가 많으면 ? => 톱을 높인다
            if (mid < answer) {
                answer = mid;
            }
            low = mid + 1;
        }
    }
    printf("%d", answer);
}