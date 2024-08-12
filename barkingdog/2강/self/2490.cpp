#include <iostream>

using namespace std;

int result; // 한 번 던진 네 개의 윷짝에서 배(0)와 등(1)의 합계를 저장하는 변수
int input; // 각 윷짝의 상태를 입력받는 변수
string res = "DCBAE"; // 윷놀이 결과를 저장하는 문자열입니다. 인덱스를 통해 도(A), 개(B), 걸(C), 윷(D), 모(E)를 매핑

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<3;i++) {
        result = 0;
        for(int j=0;j<4;j++) {
            cin >> input;
            result += input;
        }
        cout << res[result] << '\n';
    }

}