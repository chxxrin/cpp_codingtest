// 주어진 배열에서 특정 구간 내 최소값을 효율적으로 찾기 위해 덱을 사용하는 알고리즘을 구현
// 슬라이딩 윈도우 최솟값 알고리즘 문제
// 각 숫자를 한 번씩만 처리하므로 시간 복잡도는 O(n)

#include <iostream>
#include <deque>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; // 배열의 크기
    int l; // 구간의 크기

    deque<pair<int, int>> DQ; // (해당값의 인덱스, 값) = (위치, 값)

    cin >> n >> l;

    for(int i=0;i<n;i++) {
        int num; // 숫자들을 차례로 입력
        cin >> num;
        // 새로운 숫자가 deque내에서 가장 큰 값의 숫자이고 마지막에 위치하도록 합니다.
        // deque안의의 숫자들은 오름차순 상태를 유지하게 되고, 구간내 가장 작은값은 항상 맨앞(front)에 있는 상태를 가지게 됩니다.
        while(!DQ.empty() && DQ.back().second >= num) { //맨뒤의 값이 삽입하려는 num보다 크다면 빼!
            DQ.pop_back();
        }
        // 새로운 숫자는 항상 삽입됩니다.
        DQ.push_back({i, num}); // 위치 i에 num을 새롭게 입력

        // 주어진 구간을 벗어나는 outdate된 숫자들은 제거해줍니다.
        if(DQ.front().first <= i-l) { // 위치가 i-l보다 작으면
            DQ.pop_front(); // 앞에거 빼!
        }

        cout << DQ.front().second << " "; // 앞의 값들을 출력!(오름차순이므로 가장 작은 값)
    }
    return 0;


}