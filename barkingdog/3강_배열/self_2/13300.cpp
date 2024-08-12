#include <iostream>

using namespace std;

int student[2][7];
int n, k;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> k;
    for(int i=0;i<n;i++) {
        int s,y;
        cin >> s >> y;
        student[s][y]++;
    }

    int cnt = 0;
    for(int i=0;i<2;i++) { // 0,1
        for(int j=1;j<7;j++) { // 1~6
            cnt += student[i][j] / k;
            if(student[i][j] % k) ++cnt;
        }
    }
    cout << cnt;

}