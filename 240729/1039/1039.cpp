#include <cstdio>
#include <queue>
using namespace std;

int n; // 0으로 시작하지 않는 정수
int k; // 연산 횟수
int m; // 숫자의 길이, 자리수
int vt[1000010]; // N의 최댓값 1,000,000
queue<int> q;

int my_len(int num) {
    int cnt = 0;
    while (num > 0) {
        cnt++;
        num /= 10;
    }
    return cnt;
}

// 문자열을 정수로 변환하는 나의 함수
int my_to_int(char buf[]) {

    int res = 0;
    for (int i = 0; i < m; i++) {
        // 문자를 정수로 변환       
        int x = buf[i] - '0';
        res = res * 10;
        res += x;
    }
    return res;
}

// i, j를 교환을 해서 반환
// 안되면 -1을 리턴
int change(int num, int i, int j) {
    // num -> string
    // num 하나씩 하나씩 찾아서
    char buf[32];
    // 숫자를 -> 문자열로 변환
    sprintf(buf, "%d", num);    

    // i와 j를 교환
    // 조건
    // 1 <= i < j <= m
    if (0 <= i && i < j && j <= m - 1) {
        char tmp;
        tmp = buf[i];
        buf[i] = buf[j];
        buf[j] = tmp;

        // 문자열을 -> 숫자로 변환
        // 만약에 앞자리가 0이면 교환하지 말자
        if (buf[0] == '0') {
            return -1;
        }
        return my_to_int(buf);
    }
    else {
        return -1;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    m = my_len(n); // m은 n의 자릿수
    q.push(n); // 정수 n을 큐에 넣기
    
    // BFS 시작
    for (int l = 1 ; l <= k ; l++) {        
        int sz = q.size();
        while (sz-- > 0) {
            int cur = q.front();
            q.pop();            
            for (int i = 0 ; i < m ; i++) {
                for (int j = i + 1 ; j < m ; j++) {
                    int tmp = change(cur, i, j);
                    if (tmp == -1) continue;
                    if (vt[tmp] == l) continue;
                    vt[tmp] = l;
                    q.push(tmp);
                }
            }
        }
    }
    // 가장 큰 숫자가 존재하면 출력
    for (int i = 1000000 ; i >= 1 ; i--) {
        if (vt[i] == k) {
            printf("%d", i);
            return 0;
        }
    }
    // 가장 큰 숫자가 없으면 -1 출력
    printf("-1");   
}