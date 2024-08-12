#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(true){
    string a;
    getline(cin, a); // 공백있는 문자열은 getline()

    if(a == ".") break; // . 이면 끝낸다

    stack<char> s; // 문자를 스택에 넣을거니까 <char>형
    bool isValid = true; // true를 초기값으로함

    for(auto c : a){
      if(c == '(' || c == '[') s.push(c);
      else if(c == ')'){
        if(s.empty() || s.top() != '('){
          isValid = false;
          break;
        }
        s.pop();
      }
      else if(c == ']'){
        if(s.empty() || s.top() != '['){
          isValid = false;
          break;
        }
        s.pop();
      }
    }
    // 끝까지 문자열을 다 돌았는데 스택이 비어있지 않다면 잘못된 괄호를 가졌기 때문에 false
    if(!s.empty()) isValid = false; 

    // isValid가 true라면 올바른 괄호짝을 가졌으므로 true!
    if(isValid) cout << "yes\n";
    else cout << "no\n"; // 그게 아니라 isValid가 false라면 no!
  }
}