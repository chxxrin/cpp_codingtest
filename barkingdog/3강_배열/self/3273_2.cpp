#include <iostream>

using namespace std;

int arr[1000005];
bool occur[2000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int answer = 0;
    for(int i=0;i<n;i++) {
        if(x-arr[i] > 0 && occur[x-arr[i]] == true) {
            answer++;
        }
        occur[arr[i]] = true;
    }
    cout << answer;
}