#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1;
    string str2 = "Hello World";
    string str3(str2);
    string str4(str2, 0, 5);
    string str5(10, '*');

    string str = "Hello, C++ world!";

    size_t pos1 = str.find("Hello");
    cout << pos1 << '\n'; //0

    size_t pos2 = str.find('C');
    cout << pos2 << '\n'; // 7

    size_t start_index = 2;
    size_t pos3 = str.find("Hello", start_index);
    cout << pos3 << '\n';

    size_t pos4 = str.find("Python");
    cout << pos4 << '\n';

    return 0;
}