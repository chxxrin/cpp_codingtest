// 나무 자르기
#include <cstdio>

int n, m, tree[1000000];

// h 높이의 톱으로 나무를 자를때 얻게 되는 나무의 양 구하기
long long cut(int h) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (tree[i] > h) {
            sum += tree[i] - h;
        }
        // 중간에 이미 sum이 목표치를 넘어간다면?????
    }
    return sum;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
    }
    // 0 ~ 1000000000 범위에서 톱을 사용해본다.
    // 하나씩 하면 시간이 오래 걸릴테니 반씩 알아본다
    // lo ~ hi 범위에 있다고 가정하고, 적절한 값을 찾는다.
    int lo = 0;
    int hi = 1000000000;
    int mid;
    int answer = 0;

    // 범위를 벗어나지 않으면 계속 값을 찾는다.
    while (lo <= hi) {      
        mid = (lo + hi) / 2;    // integer 범위를 벗어 날까??
        long long tmp = cut(mid);   // 범위의 중간 값으로 톱을 사용해본다.
        //printf("%d %d %lld\n", lo, hi, tmp);
        // 딱 알맞는 나무를 얻었으면?
        if (tmp == m) {
            printf("%d", mid);
            return 0;
        }
        // 나무가 부족하면? => 톱을 낮춘다
        else if (tmp < m) {
            hi = mid - 1;
        }
        // 나무가 많으면? => 톱을 높혀본다
        else {
            if (mid < answer) {
                answer = mid;
            }
            lo = mid + 1;
        }
    }
    printf("%d", answer);
}