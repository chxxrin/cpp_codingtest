// L개의 알파벳 소문자
// 최소 한개의 모음
// 최소 2개의 자음
// 알파벳 오름차순
// 종류 : C가지

#include <cstdio>
#include <vector> // 내가 담을려는 문자열을 담기 위해 벡터 사용

using namespace std;

int L; // 암호에 사용되는 알파벳 개수
int C; // 암호로 사용했을 법한 문자의 종류
char buf[4]; // 문자열을 받는 buffer 하나 생성 
bool check[256];  
vector<char> alpha; // 주어진 알파벳
vector<char> crypto; // 암호

// 암호 출력
void print_str() {
    for (int i = 0; i < L; i++) {
        printf("%c", crypto[i]);
    }
    printf("\n");
}

// 만들어진 암호(crypto)가 정상인지 비정상인지 확인하는 코드
// 정상=true, 비정상=false
// 모음 1개 이상, 자음 2개 이상
bool isvalid() {
    int moeum_count = 0;
    int jaeum_count = 0;
    if(crypto.size() != L){
        return false;
    }

    for (int i=0;i< L; i++) {
        // 만약에 모음이면 moeum_count++;
        // 자음이면 jaeum_count++;
        if (crypto[i] == 'a' || crypto[i] == 'e' || crypto[i] == 'i' || crypto[i] == 'o' || crypto[i] == 'u') {
            moeum_count++;
        }
        else {
            jaeum_count++;
        }
    }
    // 모음이 1개 이상, 자음이 2개 이상이면
    if (moeum_count >= 1 && jaeum_count >= 2){
        return true;
    } else {    // 아니면
        return false;
    }
}

// 만드는 법
// alpha에서 i번째 문자를 넣을지 말지
// 넣는다면 crypto의 뒤에 붙인다
// 재귀!
void brute(int i) {
    // 종료 조건
    if (i>=C) { // 최대길이 C보다 크다면 종료
        if(isvalid()){
            print_str();
        }
        return; 
    }
    
    // i 번째 문자를 넣을까 말까?
    // 아직 암호의 크기가 L이 아니라면 넣을 수 있음
    // 그래서 crypto에 alpha[i]를 push_back()으로 넣고
    // brute(i+1) 을 호출해서 다음거를 재귀호출한다!
    if(crypto.size() < L) {
        crypto.push_back(alpha[i]);
        brute(i+1); 
        crypto.pop_back();
    }
    // 아니면 넣지않고 바로 다음으로 넘어간다
    brute(i+1);
}

int main() {
    scanf("%d %d", &L, &C);
    for(int i=0;i<C;i++) {
        scanf("%s", buf); // 문자열로 받기
        // check 변수를 이용
        check[buf[0]] = true;
    }
    // check 입력 받은 것을 순서대로 출력 가능? == 정렬
    // 사전순으로 정렬!!!
    for (int i='a' ; i<='z';i++) {
        if(check[i] == true) {
            alpha.push_back(i);
        }
    }
    // bruteforce로 0번부터 출력하세요
    brute(0); 
}