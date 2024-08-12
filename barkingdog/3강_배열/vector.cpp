#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;


// vector : 배열과 비슷한데 크기를 마음대로 늘리고 줄일 수 있다
// vector에서 = 를 사용하면 deep copy가 된다

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v1(3,5); // {5,5,5}
    cout << v1.size() << '\n'; // 3
    v1.push_back(7); // {5,5,5,7}

    vector<int> v2(2); // {0,0}
    v2.insert(v2.begin()+1, 3); // {0,3,0}

    vector<int> v3 = {1,2,3,4}; // {1,2,3,4}
    v3.erase(v3.begin()+2); // {1,2,4}

    vector<int> v4; // {}
    v4 = v3; // {1,2,4}
    cout << v4[0] << v4[1] << v4[2] << '\n'; // 124
    v4.pop_back(); // {1,2}
    v4.clear(); // {}

    //[2] 
    vector<int> v11 = {1,2,3,4,5,6};

    // 1. range-based for loop (since C++11)
    // e에 v1이 하나씩 들어감
    for(int e:v11){
        cout << e << ' ';
    }

    // 2. not bad
    for(int i=0;i<v11.size();i++) {
        cout << v11[i] << ' ';
    }

    // 3. wrong
    for int(int i=0;i<=v11.size()-1;i++){
        cout << v11[i] << ' ';
    }
}