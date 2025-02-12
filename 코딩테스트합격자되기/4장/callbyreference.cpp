#include <iostream>

using namespace std;

void modify(int& value) {
    value = 10;
    cout << "주소: " << &value << '\n';
    cout << "값: " << value << '\n'; 
 }

int main() {
    int value = 5;
    cout << "주소: " << &value << '\n';
    cout << "값: " << value << '\n'; 
    modify(value);
    cout << "주소: " << &value << '\n';
    cout << "값: " << value << '\n'; 
    return 0;
}