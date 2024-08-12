#include <cstdio>
#include <map> // 시간복잡도 때문에 map을 사용함


using namespace std;

// 무조건 이렇게 풀어야함..
int n;
int m;
int a[100000];
int b[100000];
map<int, int> check; // key가 int, value가 int인 값을 받아서 

int main() {
    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%d", &a[i]);
        // map을 사용
        check[a[i]] = 1;
    }
    scanf("%d", &m);
    for (int i=0;i<m;i++) {
        scanf("%d", &b[i]);
        printf("%d\n", check[b[i]]);
    }

}