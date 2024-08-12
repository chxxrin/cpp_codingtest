#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n, ans = 0;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while (n--) {
    string a;
    cin >> a;
    stack<int> S;
    for (auto c : a) {
      if (!S.empty() && S.top() == c) S.pop(); // 스택이 비어있지 않고, 스택의 최상단 문자와 현재 문자가 같으면 스택에서 팝합니다.
      else S.push(c); // 그렇지 않으면 현재 문자를 스택에 푸시
    }
    if (S.empty()) ans++; // 문자열 순회가 끝난 후 스택이 비어있으면 좋은 단어이므로 ans를 증가
  }
  cout << ans << "\n";
}