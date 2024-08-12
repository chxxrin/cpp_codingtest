#include <cstdio>

// 코테에서 쓸 변수들은 전역변수로 하면 편함
int n, k;
char word[50][20];
bool check_alpha[256]; // 선택이 되면 true, 안되면 false (일단 초기화는 false로 다 들어가있음)
int choose_count; // 알파벳 몇개를 골랐는지
int answer;

void print_alpha() {
    for(int i='a';i<='z' ; i++) {
        if(check_alpha[i] == true) {
            printf("%c ", i);
        }
    }
    printf("\n");
}

// check_alpha에 있는 알파벳만으로
// 주어진 단어를 이해할 수 있는지 counting
// 최대 단어도 같이 저장
void check_word() {
    int count = 0;
    for(int i=0; i<n ; i++) {
        // 주어진 알파벳으로 단어를 이해할 수 있나 없나
        // counting
        bool suc = true;
        for(int j=0;word[i][j];j++) {
            if (check_alpha[word[i][j]] == false) {
                suc = false;
                break;
            }
        }
        if(suc){
            count++;
        }
    }
    if (count > answer) {
        answer = count;
    }
}

void pick(int pick_alpha) {
    if(choose_count == k) {
        // 출력    
        // print_alpha();
        check_word();
        return;
    }

    if(pick_alpha > 'z')
        return;

    if ((pick_alpha != 'a') && (pick_alpha != 'n')&& (pick_alpha != 't')&& (pick_alpha != 'i')&& (pick_alpha != 'c')) {
        check_alpha[pick_alpha] = true;
        choose_count++;

        pick(pick_alpha + 1);
        check_alpha[pick_alpha] = false;
        choose_count--; 
        pick(pick_alpha + 1);

    }
    else {
        pick(pick_alpha + 1);
    }

}

int main() {
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;i++) {
        scanf("%s", word[i]);
    }

    // a, n, t, i, c
    check_alpha['a'] = true;
    check_alpha['n'] = true;
    check_alpha['t'] = true;
    check_alpha['i'] = true;
    check_alpha['c'] = true;
    choose_count = 5;

    pick('a');
    printf("%d", answer);


}