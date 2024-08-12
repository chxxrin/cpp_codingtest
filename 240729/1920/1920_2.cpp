#include <iostream>
#include <map>

using namespace std;

// 이거 다 시간초과 남 ㅠㅠ 
int main() {
    ios::sync_with_stdio(false);  
    cin.tie(NULL); 

    int n, m;
    cin >> n;
    
    map<int, int> check; 

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        check[num] = 1; 
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int answer;
        cin >> answer;
        cout << check[answer] << endl;
    }

    return 0;
}
