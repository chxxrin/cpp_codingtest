#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> v1;
    vector<int> v2 = {1,2,3,4,5};
    v2[2] = 7;

    for(auto i=v2.begin(); i != v2.end() ; i++) {
        cout << *i << '\n';
    }
    cout << '\n';

    for (int num : v2) {
        cout << num << ' ';
    }
    cout << '\n';


    vector<int> v3(4,3);
    vector<int> v4(v3);

    vector<vector<int>> v11;
    
    int rows = 3;
    int cols = 4;
    vector<vector<int>> v22(rows, vector<int>(cols));

    int val = 9;
    vector<vector<int>> v33(rows, vector<int>(cols,val));

    vector<vector<int>> v44 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<int> v5 = {2,3,4,5};
    v5.push_back(6);
    v5.pop_back();
    
    vector<int> v6 = {2,3,4,5};
    v6.insert(v6.begin(), 1);
    v6.erase(v6.begin());
    return 0;


}