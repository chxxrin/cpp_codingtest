#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
int a[1010][1010]; // 입력배열
int d[1010][1010]; // dp배열

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    string s;
    cin >> s;
    for(int j = 1; j <= m; ++j)
      a[i][j] = s[j-1] - '0';  // 입력 문자열을 정수 배열로 변환
  }
  int maxlen = 0; // 최대 정사각형의 한 변의 길이
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      if(a[i][j]){
        d[i][j] = min({d[i-1][j-1], d[i-1][j], d[i][j-1]}) + 1; // arr[i][j] == 1, a[i][j]가 1일 때, 해당 위치를 오른쪽 아래 꼭짓점으로 하는 정사각형의 한 변의 길이
        maxlen = max(maxlen, d[i][j]);
      }
    }
  }
  cout << maxlen * maxlen;
}