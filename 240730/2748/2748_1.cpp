#include <iostream>
#include <vector>

using namespace std;

vector<long long> F;

long long fibo (int num) {
    
    F.push_back(0);
    F.push_back(1);

    if (num < 2) {
        return num;
    } else {
        for (int i=2;i<=num;i++) {
            F.push_back(F[i-1]+F[i-2]);
            //memoization : F[i-1],F[i-2]를 다시 계산하지 않고 저장된 값을 꺼내서 씀

        }
    }
    return F[num];
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n) << endl;
}


