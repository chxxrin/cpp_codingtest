// 수찾기
// 미리 배열을 정렬해둔 다음 이분탐색을 사용

#include <iostream>

using namespace std;

int a[100005];
int n;
int m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    // binary_search(s, e, t)를 사용하기 위해 정렬 sort()을 먼저 수행
    // a : start
    // a+n : end
    // t : target
    sort(a, a+n);

    cin >> m;
    while(m--) {
        int target;
        cin >> target;
        cout << binary_search(a, a+n, target) << endl;
    }

}
