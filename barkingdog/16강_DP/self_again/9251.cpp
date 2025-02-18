#include <iostream>
#include <string>

using namespace std;

string a, b; 
int d[1005][1005]; // d 배열은 주어진 두 문자열 a와 b의 최장 공통 부분 수열 (LCS, Longest Common Subsequence)을 찾기 위한 동적 계획법 (DP) 테이블
// 이 배열의 각 요소 d[i][j]는 문자열 a의 첫 i개의 문자와 문자열 b의 첫 j개의 문자 사이의 LCS의 길이를 저장

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    
    int len_a = a.length();
    int len_b = b.length();

    for(int i=1;i<=len_a;i++) {
        for(int j=1;j<=len_b;j++) {
            if(a[i-1] == b[j-1]) { // 두 문자가 같으면, 이전까지의 LCS에 현재 문자를 추가하므로 1을 더함
                d[i][j] = d[i-1][j-1] + 1;
            } else { // 두 문자가 다르면, 하나를 제외한 경우 중 LCS가 더 긴 값을 선택
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
            
        }
       
    }
    cout << d[len_a][len_b];
}

// d[i][j] = a의 i-1번째 글자와 b의 j-1번째 글자까지 최장 공통 부분수열
// 최장 공통부분 수열을 보존하기 위해 2중 for문을 사용
// d[i][j] --> if(a[i-1] == b[j-1])이면 d[i-1][j-1] + 1
// d[i][j] --> if(a[i-1] != b[j-1])이면 max(d[i-1][j], d[i][j-1])
// 초기값은 d[1][1]에 a[0]과 b[0]이 같을 때와 a[0]과 b[0]이 다를 때 각각 다른 값을 저장