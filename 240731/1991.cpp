// 트리 순회
#include <iostream>
using namespace std;

int n;
int tree[128][2];

void pre_order(char node) {
    if (node == '.') {
        return;
    }
    cout << node;
    pre_order(tree[node][0]);
    pre_order(tree[node][1]);
}

void in_order(char node) {
    if (node == '.') {
        return;
    }

    in_order(tree[node][0]);
    cout << node;
    in_order(tree[node][1]);
}

void post_order(char node) {
    if (node == '.') {
        return;
    }

    post_order(tree[node][0]);
    post_order(tree[node][1]);
    cout << node;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        char s1[4], s2[4], s3[4];
        char a, b, c;
        cin >> s1 >> s2 >> s3;
        tree[s1[0]][0] = s2[0];
        tree[s1[0]][1] = s3[0];
    }
    pre_order('A');
    cout << '\n';
    in_order('A');
    cout << '\n';
    post_order('A');
    cout << '\n';
}