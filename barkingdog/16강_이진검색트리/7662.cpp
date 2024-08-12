#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  
  while(t--){
    int k;
    cin >> k;

    multiset<int> ms; // 중복된 원소가 있을 수 있으므로 multiset 사용

    while(k--){
      char com;
      cin >> com;

      if(com == 'D'){
        int q;
        cin >> q;

        if(ms.empty()) continue;
        if(q == 1) ms.erase(prev(ms.end())); // Q에서 최댓값을 삭제
        else ms.erase(ms.begin()); // Q 에서 최솟값을 삭제
      }
      else{
        int q;
        cin >> q;
        ms.insert(q);
      }
    }
    if(ms.empty()) cout << "EMPTY\n";
    else{
      cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }
  }
}