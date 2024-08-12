#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true) {
        string str;
        getline(cin, str);

        if(str == ".") {
            break;
        }

        stack<char> S;
        bool isValid = true;

        for(auto c: str) {
        if(c == '(' || c == '[') {
            S.push(c);
        } else if(c == ')') {
            if(S.empty() || S.top() != '(') { // 안되는 조건
                isValid = false;
                break;
            } 
            S.pop(); // (가 있는데, )를 넣었으면 짝이 맞으므로 ( 이거 빼!
        } else if(c == ']') {
            if(S.empty() || S.top() != '[') {  // 안되는 조건
                isValid = false;
                break;
            } 
            S.pop(); // [가 있는데, ]를 넣었으면 짝이 맞으므로 [ 이거 빼!
        }
    }
        if(!S.empty()) { // 만약 스택이 비어있지 않다면 짝이 안맞아서 pop하지 못한거니까
            isValid = false; // false!
        }
        if(isValid) { // 만약 isValid가 true여서 유효하다면 
            cout << "yes" << '\n'; // yes출력
        } else {
            cout << "no" << '\n'; // false라서 유효하지 않다면 no출력!
        }
    }
}