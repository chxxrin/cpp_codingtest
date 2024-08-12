#include <iostream>
#include <stack>

using namespace std;

#define X first // 타워의 높이
#define Y second // 인덱스

stack<pair<int, int>> tower; // 타워의 높이와 인덱스를 저장할 스택
int n; // 타워의 개수를 저장할 변수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    tower.push({100000001, 0}); // 아주 높은 타워를 초기 값으로 스택에 넣음

    for(int i=1;i<=n;i++) {
        int height;
        cin >> height;

        while(tower.top().X < height) { // 스택의 최상단에 있는 타워의 높이가 현재 타워의 높이보다 작으면 스택에서 제거
            tower.pop();
        }
        cout << tower.top().Y << ' '; // 스택의 최상단에 있는 타워의 인덱스를 출력, 이 타워는 현재 타워보다 높으면서 가장 가까운 왼쪽 타워
        tower.push({height, i}); // 현재 타워의 높이와 인덱스를 스택에 추가
    }
}