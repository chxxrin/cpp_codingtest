#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    stack<int> S;

    int num;
    int sum = 0;
    for (int i=0;i<k;i++){
        cin >> num;
        S.push(num);
        if(num == 0) {
            S.pop();
            sum -= S.top();
            S.pop();
        }
        sum += num;
    }
    cout << sum;

}