// 사탕 상자
#include <iostream>

#define SZ (1<<20)  // 원소의 개수 1000000 은 대략 2^20

using namespace std;

int n;
int tr[SZ * 2];     // index tree

// pos에 val 만큼 더한다. (교체가 아님)
void update(int pos, int val) {
    pos += SZ;
    while (pos >= 1) {
        tr[pos] += val; // 값을 val 만큼 변경하는데, 부모까지 몽땅
        pos /= 2;
    }
}

// k 번째에 해당하는 위치를 구한다.
int findk(int k) {
    int pos = 1;

    while (pos < SZ) {
        // 왼쪽 자식에 k 번째가 있을까?
        if (tr[pos * 2] >= k) {
            pos = pos * 2;
        }
        else {
            k -= tr[pos * 2];
            pos = pos * 2 + 1;
        }
    }

    return pos - SZ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n-- > 0) {
        int a, b, c;
        cin >> a >> b;
        if (a == 2) {
            cin >> c;
            // b 만큼 매운 사탕을 c만큼 추가한다.
            update(b, c);
        }
        else {
            int x = findk(b);
            // b 번째 매운 사탕을 찾아서 출력하고
            cout << x;
            // 그 사탕을 하나 먹는다.
            update(x, -1);
        }
    }
}