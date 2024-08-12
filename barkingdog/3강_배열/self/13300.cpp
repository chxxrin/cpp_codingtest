#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; // 학생수
    int k; // 최대 인원수 
    int s[2][7] = {}; // 성별(2가지)과 학년(1~6학년)의 학생 수를 저장하는 2차원 배열
    int cnt = 0; // 방 개수

    cin >> n >> k;

    // 입력에 대해서 배열 갯수 증가시킴
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        s[a][b]++;
    }

    // 필요한 방의 개수 계싼
    for(int i=0;i<2;++i) { // 성별(0과 1)과 
        for(int j=1;j<7;++j) { // 학년(1부터 6)별로 학생 수를 확인
            cnt += s[i][j] / k; // 각 성별/학년별 학생 수를 최대 인원수 k로 나누어 방의 개수를 추가
            if(s[i][j] % k) ++cnt; //학생이 남을 경우 , 하나의 방이 더 필요하므로 방 개수 추가
        }
    }
    cout << cnt;
}