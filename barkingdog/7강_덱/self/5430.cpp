// AC 문제 : 주어진 명령어 시퀀스에 따라 배열을 뒤집거나 특정 요소를 제거하는 작업을 수행


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int t;
    cin >> t;

    while (t--) {
        string order; // 명령어 문자열 
        string str; // 숫자 배열
        bool reverse=false; // 뒤집기 명령을 추적하기 위한 부울 변수
        bool error=false; // 명령어 수행 중 에러가 발생했는지 추적하기 위한 부울 변수
        deque<int> dq; // 숫자를 저장할 덱을 선언

        cin >> order;
        cin >> n;
        cin >> str;

        // 숫자 배열 파싱 : 입력받은 문자열 str을 파싱하여 숫자를 deque에 저장
        string s = ""; // 현재 숫자를 임시로 저장하는 문자열
        for (int i = 0; i<str.length();i++) {

            if (isdigit(str[i])) { // 문자가 숫자인지 확인
                s += str[i];
            }
            else { //숫자가 아닌 문자를 만나면 
                if (!s.empty()) {
                    dq.push_back(stoi(s)); // stoi(s)를 사용하여 문자열을 정수로 변환하고 덱의 뒤쪽에 삽입
                    s = "";
                }
            }
        }

        for (auto o : order) {
            if (o == 'R') { //  R인 경우 reverse 부울 값을 반전
                if (reverse)
                    reverse = false;
                else
                    reverse = true;
            }
            else { // D인 경우 덱이 비어 있는지 확인
                if (dq.empty()) { // 비어 있다면 error를 출력하고 error 부울 값을 true로 설정한 뒤 반복문을 종료
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
                if (reverse) // reverse가 true이면 
                    dq.pop_back(); // dq.pop_back()을 호출하고, 
                else // 그렇지 않으면 
                    dq.pop_front(); // dq.pop_front()를 호출하여 앞에서 제거
            }
        }
        if (!error) { // error가 false인 경우 결과를 출력
            cout << '[';
        }
        if (reverse && !dq.empty()) { // reverse가 true인 경우 덱을 뒤집어 출력
            for (auto o = dq.rbegin(); o != dq.rend(); o++) {
                if (o == dq.rend() - 1)
                    cout << *o;
                else // 그렇지 않으면 덱을 그대로 출력
                cout << *o << ',';
            }
        }
        else if (!reverse&&!dq.empty()){
            for (auto o = dq.begin(); o != dq.end(); o++) {
                if (o == dq.end() - 1) // 덱의 마지막 원소를 출력할 때는 쉼표를 제외하고 출력
                    cout << *o;
                else
                cout << *o << ',';
            }
        }
        if(!error)
        cout <<"]\n";

    }
}