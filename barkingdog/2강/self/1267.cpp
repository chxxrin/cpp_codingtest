#include <iostream>

using namespace std;

int n; //통화의 개수
int call[10010]; // 통화 시간들
int Y; // 영식요금제
int M; // 민식요금제

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    // 시간 입력받기
    for(int i=0;i<n;i++) {
        cin >> call[i];
    }

    // 1. 영식 요금제 
    for(int i=0;i<n;i++) {
        Y += ((call[i] / 30) + 1) * 10;
    }

    // 2. 민식 요금제 
    for(int i=0;i<n;i++) {
        M += ((call[i] / 60) + 1) * 15;
    }

    if(Y < M) { // 만약 영식 요금제가 싸면
        cout << "Y " << Y; // 영식요금제와 요금을 출력
    } else if(Y > M) { // 만약 민식 요금제가 싸면
        cout << "M " << M; // 민식요금제와 요금을 출력
    } else { // 만약 둘다 같으면
        cout << "Y M " << Y; // 영식 민식 순서로 쓰고 요금을 출력
    }
    

}