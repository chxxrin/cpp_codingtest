// 이 코드는 문자열을 순회하며 레이저와 막대를 구분하여 처리합니다. 
// 스택을 사용하여 현재까지 처리한 막대의 개수를 추적하며, 레이저가 나타날 때마다 스택에 남아있는 막대의 개수를 결과에 더합니다. 
// 막대의 끝을 만날 때마다 결과에 1을 더하여 총 막대의 조각 개수를 계산합니다.

#include <iostream>
#include <string>
#include <stack>

using namespace std;
string s;
long long ans = 0;
stack<char> st;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  int sz = s.length();
  for (int i = 0; i < sz; i++) {
    if (s[i]=='(')
      st.push(s[i]);
    else { // 현재 문자가 닫는 괄호 ')'인 경우 두 가지 경우를 나누어 처리
      if (s[i-1] == '(') { // 바로 앞 문자가 여는 괄호 '('인 경우: 레이저
        st.pop(); // 스택에서 하나를 팝하고,
        ans += st.size(); //  현재 스택에 남아있는 막대의 개수를 ans에 더합니다
      }
      else { // 바로 앞 문자가 닫는 괄호 ')'인 경우: 막대의 끝
        st.pop();  // 스택에서 하나를 팝하고,
        ans++; // 막대 1개가 절단된 것과 동일한 상황이므로 ans에 1 추가
      }
    }
  }
  cout << ans << "\n";
  return 0;
}