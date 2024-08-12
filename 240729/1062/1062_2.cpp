#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 전역 변수 선언
int n, k;
vector<string> words(50);
vector<bool> check_alpha(256, false); // 선택이 되면 true, 안되면 false (일단 초기화는 false로 다 들어가있음)
int choose_count; // 알파벳 몇 개를 골랐는지
int answer;

void print_alpha() {
    for (char c = 'a'; c <= 'z'; c++) {
        if (check_alpha[c]) {
            cout << c << " ";
        }
    }
    cout << endl;
}

// check_alpha에 있는 알파벳만으로 주어진 단어를 이해할 수 있는지 counting
// 최대 단어도 같이 저장
void check_word() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        // 주어진 알파벳으로 단어를 이해할 수 있나 없나 counting
        bool suc = true;
        for (char c : words[i]) {
            if (!check_alpha[c]) {
                suc = false;
                break;
            }
        }
        if (suc) {
            count++;
        }
    }
    if (count > answer) {
        answer = count;
    }
}

void pick(char pick_alpha) {
    if (choose_count == k) {
        check_word();
        return;
    }

    if (pick_alpha > 'z')
        return;

    if (pick_alpha != 'a' && pick_alpha != 'n' && pick_alpha != 't' && pick_alpha != 'i' && pick_alpha != 'c') {
        check_alpha[pick_alpha] = true;
        choose_count++;

        pick(pick_alpha + 1);

        check_alpha[pick_alpha] = false;
        choose_count--;
    }
    pick(pick_alpha + 1);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    // a, n, t, i, c
    check_alpha['a'] = true;
    check_alpha['n'] = true;
    check_alpha['t'] = true;
    check_alpha['i'] = true;
    check_alpha['c'] = true;
    choose_count = 5;

    pick('a');
    cout << answer << endl;

    return 0;
}
