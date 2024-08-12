#include <iostream>
#include <vector>
#include <unordered_set>

// 시간초과가 남 ㅠㅠㅠ
// 아마 map을 안써서 일거임
// 1920_2.cpp 보자
using namespace std;

int main() {
    int N, M;
    
    cin >> N;
    vector<int> a(N);  // N의 크기로 벡터 a를 초기화
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cin >> M;
    vector<int> b(M);  // M의 크기로 벡터 b를 초기화
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }

    // 배열 a의 요소를 set에 저장
    unordered_set<int> a_set(a.begin(), a.end());

    // 각 요소 b[i]가 a_set에 있는지 검사
    for (int i = 0; i < M; i++) {
        if (a_set.find(b[i]) != a_set.end()) {
            cout << 1 << " " << endl;
        } else {
            cout << 0 << " " << endl;
        }
    }
    
    cout << endl;
    return 0;
}
