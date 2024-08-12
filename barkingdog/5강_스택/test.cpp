#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

// x를 스택의 추가자리에 넣음
void push(int x){
  dat[pos++] = x;
}

// 그냥 한 칸만 내리면 저절로 사라짐
void pop(){
  pos--;
}

int top(){
  return dat[pos-1];
}

void test(){
  push(5); push(4); push(3); // top 3 4 5 bottom
  cout << top() << '\n'; // 3
  pop(); // 3 out
  pop(); // 4 out
  cout << top() << '\n'; // 5
  push(10); push(12); // top 12 10 bottom
  cout << top() << '\n'; // 12
  pop(); // 12 out
  cout << top() << '\n'; // 10
}

int main(void) {
	test();
}