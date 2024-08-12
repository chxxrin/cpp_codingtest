#include <cstdio>

// 입력 받을 변수 선언
int n; // 사진틀의 개수
int k; // 후보 추천 횟수
int a[1000]; //추천 받은 후보들

// 사용할 변수 선언
int pic_frame[21]; // 사진틀-후보들 번호를 부여하려고 했음(1~100)
int count[101]; // 후보 추천 횟수
int last_time[101]; // 후보 추천 시각

// 비어있는 사진틀 반환
// 있으면 사진틀의 번호
// 없으면 -1
int get_empty_frame() {
    for(int i = 0; i < n; i++) {
        if(pic_frame[i] == 0) {
            return i;
        }
    }
    return -1;
}

// 사진틀에서 뺄 사람 반환
int get_out_person() {
    // 1~100 후보가 있음
    int min_count = 100000;
    int min_time = 100000;
    int person_number = -1; 

    // 후보를 돌면서 추천수를 비교해서 최소 추천수를 구하는데
    // 추천수가 최소인것이 또 나타나면 최근 등록시간을 비교
    // 최근 등록시간이 오래된 사람을 제거
    for (int i = 1; i <= 100; i++) {
        if (count[i] == 0) {
            continue;
        }
        if(count[i] < min_count) {
            min_count = count[i];
            person_number = i;
            min_time = last_time[i];
        } else if(count[i] == min_count) {
            if(last_time[i] < min_time) {
                person_number = i;
                min_time = last_time[i];
            }
        }
    }
    return person_number;
}

// 그 사람의 frame 번호 반환
int get_person_frame(int num) {
    for(int i = 0; i < n; i++) {
        if(pic_frame[i] == num) {
            return i;
        }
    }
    return -1;
}

// // 추천수가 가장 적은 후보를 내놔라
// // 있으면 후보번호
// // 없으면 -1
// int get_minimum_count_person() {
//     // 1. 가장 적은 후보가 두명 이상이면 => 최솟값
//     // 2. 나타나지 않은 후보의 처리 => 추천수가 0인것은 제외
//     int minimum_value = 123456;
//     int person_number = -1;
//     int minimum_count = 0;

//     for(int i = 1; i <= 100; i++) {
//         // 만약 내가 보고 있는 사람의 값이 최솟값보다 작다면
//         if(count[i] > 0 && count[i] < minimum_value) {
//             minimum_value = count[i];
//             person_number = i;
//             minimum_count = 1;
//         } else if(count[i] == minimum_value) {
//             minimum_count++;
//         }
//     }
//     if(minimum_count > 1) {
//         return -1;
//     }
//     return person_number;
// }

// // 추천수가 가장 적은 후보가 여러명이면
// // 가장 오래된 후보를 내놔라
// int get_old_person() {
//     int old_time = 123456;
//     int person_number;
//     for(int i = 1; i <= 100; i++) {
//         if(count[i] > 0 && last_time[i] < old_time) {
//             old_time = last_time[i];
//             person_number = i;
//         }
//     }
//     return person_number;
// }



int main() {
    // 입력받기
    scanf("%d", &n);
    scanf("%d", &k);

    for(int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
    }

    // 후보별로 처리
    for(int i = 0; i < k; i++) {
        // 넣어야할 사진틀의 번호
        int insert_pic_num;
        // 빼야할 후보의 번호
        int out_person_num;

        // 그 사람이 이미 있는가?
        insert_pic_num = get_person_frame(a[i]);
        if(insert_pic_num != -1) {
            count[a[i]]++;
            continue;
        }

        // 사진틀이 비어있는지?
        insert_pic_num = get_empty_frame();

        // 비어있는 사진틀이 없는 경우
        if(insert_pic_num == -1) {
            out_person_num = get_out_person();
            insert_pic_num = get_person_frame(out_person_num);

            // 후보 추천수 초기화
            count[out_person_num] = 0;
        }

        // 후보를 사진틀에 등록
        pic_frame[insert_pic_num] = a[i];
        // 후보 추천수를 +1 증가
        count[a[i]]++; // count[a[i]] = 1; 도 가능
        // 마지막 후보 추천 시각을 셋팅
        last_time[a[i]] = i;
    }

    // 출력
    for(int i = 1; i <= 100; i++) {
        if(count[i] > 0) {
            printf("%d ", i);
        }
    }
    return 0;
}
