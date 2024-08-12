#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t; // 테스트 케이스의 개수
    cin >> t;

    vector<int> results; //결과를 저장할 벡터

    for(int i=0;i<t;i++) {
        int a,b;
        cin >> a >> b;
        results.push_back(a+b); // 결과를 벡터에 저장
    }

    for(int i=0;i<t;i++) {
        cout << results[i] << '\n';
    }

}