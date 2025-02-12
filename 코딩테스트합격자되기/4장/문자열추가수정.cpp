#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "APPLE";
    str += ", World!";
    cout << str << '\n';

    str[7] = 'P';
    cout << str << '\n';

    str.replace(7,4, "Col");
    cout << str << '\n';
    return 0;
}