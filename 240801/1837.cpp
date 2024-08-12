#include <iostream>
#include <string>

using namespace std;

string p;
int k;
int prime[1000001];
int ans = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> k;

        for(int i = 2; i*i <= 1000000; i++){
        if(prime[i]) continue;
        for(int j = i + i; j <= 1000000; j+=i) prime[j] = 1;
    }


    for(int i = 2; i <= k; i++){
        int ret = 0;
        if(prime[i]) continue;
        for(int j = 0; j < p.size(); j++)
            ret = (ret * 10 + p[j] - '0') % i;
        if(!ret) { ans = i; break;}
    }
    if(ans < k) cout << "BAD" << ' ' << ans;
    else cout << "GOOD";
}