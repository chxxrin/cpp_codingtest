#include <iostream>

using namespace std;

int n, x;
int a[100005];
bool occur[2000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    cin >> x; 

    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(x-a[i] > 0 && occur[x-a[i]] == true) {
            cnt++;
        }
        occur[a[i]] = true;
    }
    cout << cnt << '\n';

}