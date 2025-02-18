#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> a;
    a.push_back(10); // 10
    a.push_back(30); // 10 30
    a.push_back(5);  // 10 30 5
    a.push_back(8);  // 10 30 5 8
    a.push_back(6);  // 10 30 5 8 6

    a.push_back(1);              // 10 30 5 8 6 1
    a.insert(a.begin(), 7);      // 7 10 30 5 8 6 1
    a.insert(a.begin() + 2, 10); // 7 10 10 30 5 8 6 1

    a[4] = -5; // 7 10 10 30 -5 8 6 1

    a.pop_back();           // 1 pop
    a.erase(a.begin() + 3); // 30 out

    cout << a.size() << endl;  // 6
    cout << a.front() << endl; // 7
    cout << a.back() << endl;  // 1
    cout << a[3] << endl;      // -5
    cout << a.at(5) << endl;   // 5번째 값 6
    a.clear();
}