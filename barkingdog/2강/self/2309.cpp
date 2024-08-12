#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
int result[7];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int sum = 0;


    for(int i=0;i<9;i++) {
        cin >> arr[i]; // 9명의 키를 입력받아서 배열에 저장하고
        sum += arr[i]; // 9명 키의 합을 sum에 저장
    }

    sort(arr, arr+9); // 9명의 키를 오름차순으로 정렬

    for(int i=0; i<9;i++) {
        for (int j=i+1;j<9;j++) {
            if((sum - (arr[i]+arr[j])) == 100) { // 만약 9명 키의 합에서 2명의 키를 뺐을 때 100이라면 걔네가 범인!
                for (int k=0;k<9;k++) {
                    if(i==k || j==k) {
                        continue; // 우리가 찾은 이상한 난쟁이는 빼고 출력
                    }
                    cout << arr[k] << '\n';
                }
                return 0;
            }
        }
    }

}