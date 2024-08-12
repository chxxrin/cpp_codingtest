#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; 
int k; 
vector<int> a(1000); 
vector<int> pic_frame(21, 0); 
vector<int> candidate_count(101, 0); 
vector<int> last_time(101, 0); 

int get_empty_frame() {
    for(int i = 0; i < n; i++) {
        if(pic_frame[i] == 0) {
            return i;
        }
    }
    return -1;
}

int get_out_person() {
    int min_count = 100000;
    int min_time = 100000;
    int person_number = -1; 

    for (int i = 1; i <= 100; i++) {
        if (candidate_count[i] == 0) {
            continue;
        }
        if(candidate_count[i] < min_count) {
            min_count = candidate_count[i];
            person_number = i;
            min_time = last_time[i];
        } else if(candidate_count[i] == min_count) {
            if(last_time[i] < min_time) {
                person_number = i;
                min_time = last_time[i];
            }
        }
    }
    return person_number;
}

int get_person_frame(int num) {
    for(int i = 0; i < n; i++) {
        if(pic_frame[i] == num) {
            return i;
        }
    }
    return -1;
}

int main() {
    cin >> n;
    cin >> k;

    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < k; i++) {
        int insert_pic_num;
        int out_person_num;

        insert_pic_num = get_person_frame(a[i]);
        if(insert_pic_num != -1) {
            candidate_count[a[i]]++;
            continue;
        }

        insert_pic_num = get_empty_frame();

        if(insert_pic_num == -1) {
            out_person_num = get_out_person();
            insert_pic_num = get_person_frame(out_person_num);

            candidate_count[out_person_num] = 0;
        }

        pic_frame[insert_pic_num] = a[i];
        candidate_count[a[i]]++; 
        last_time[a[i]] = i;
    }

    for(int i = 1; i <= 100; i++) {
        if(candidate_count[i] > 0) {
            cout << i << " ";
        }
    }
    return 0;
}
