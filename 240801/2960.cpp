#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int k;
    int cnt(0);
    cin >> n >> k;

    vector<int> prime(n+1);

    for(int i=2;i<=n;i++) {
        prime[i] = i;
    }

    for (int i = 2; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			if (prime[j] != 0)
			{
				prime[j] = 0;
				cnt++;
				if (cnt == k)
				{
					cout << j << '\n';				}
			}
		}
	}
}