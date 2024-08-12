#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 중간에 원소 삽입
// 배열의 맨 오른쪽에 있는 것부터 한 칸 뒤로 뒤로 넣는다
// 맨 뒤부터 한 칸씩 오른쪽으로 이동
void insert(int idx, int num, int arr[], int& len){
    for(int i=len; i>idx;i--) {
        arr[i] = arr[i-1];
    }
    arr[idx]=num;
    len++;
}

// 중간에 있는 원소 삭제
// 삭제하려는 것의 왼쪽부터 한 칸 앞으로 넣는다
// 해당 자리부터 한 칸씩 왼쪽으로 이동
void erase(int idx, int arr[], int& len) {
    len--; // 일단 길이를 하나 줄인다
    for(int i=idx;i<len;i++) { // 해당인덱스부터 오른쪽 맨끝까지 진행
        arr[i] = arr[i+1]; // 뒤에 있는걸 앞에 넣으면 된다
    }
}

void printArr(int arr[], int& len) {
    for(int i=0;i<len;i++) {
        cout << arr[i] << ' ';
    }
    cout << "\n\n";
}

void insert_test() {

}

void erase_test() {

}

int main() {

    // 배열 전체를 특정값으로 초기화 할 때
    int a[21];
    int b[21][21];

    //1. memset (비추천))
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);

    // 2. for (추천)
    for(int i=0;i<21;i++) {
        a[i] = 0;
    }
    for(int i=0;i<21;i++){
        for(j=0;j<21;j++) {
            b[i][j] = 0;
        }
    }

    // 3. fill (추천추천)
    fill(a, a+21, 0);
    for(int i=0;i<21;i++) {
        fill(b[i], b[i]+21, 0);
    }

    insert_test();
    erase_test();
}