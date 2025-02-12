#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        deque<int> d;
        int rev = 0;          // 덱의 순서를 뒤집었는지를 나타내는 플래그, 'R'이 나오면 뒤집은 것으로 간주하고, 'R'의 개수에 따라 뒤집는 것을 결정
        int n;                // 덱에 들어갈 숫자의 개수
        bool isWrong = false; // 잘못된 연산이 발생했을 때 true로 설정됩니다. 덱이 비었는데 'D' 연산이 실행되면 잘못된 연산으로 간주
        string query;         // 덱에 대해 수행할 연산이 담긴 문자열
        string tmp;           // 덱에 들어갈 숫자들이 담긴 문자열로, 이를 파싱하여 덱에 삽입

        cin >> query;
        cin >> n;
        cin >> tmp;

        // 숫자 파싱
        int cur = 0; // cur 변수는 현재 파싱 중인 숫자를 저장
        for (int i = 1; i + 1 < tmp.size(); i++)
        {                      // 첫 번째와 마지막 괄호는 무시
            if (tmp[i] == ',') // tmp는 [1,2,3] 이런 형태
            {
                d.push_back(cur); // tmp[i] == ','일 때 숫자를 덱에 삽입하고, 그 후 cur을 0으로 초기화하여 다음 숫자를 읽어들입니다.
                cur = 0;
            }
            else
            {
                cur = 10 * cur + (tmp[i] - '0');
            }
        }
        if (cur != 0) // 마지막 숫자는 ','로 끝나지 않기 때문에, 루프가 끝난 후 한 번 더 cur을 덱에 삽입합니다.
        {
            d.push_back(cur);
        }

        // 쿼리 처리
        for (char c : query)
        {
            // R이 나오면 rev 값을 변경합니다. rev가 0이면 덱이 원래 순서대로 있고, rev가 1이면 덱이 뒤집어진 상태
            if (c == 'R')
            {
                rev = 1 - rev;
            }
            else // c == 'D'
            {
                if (d.empty())
                {
                    isWrong = true;
                    break;
                }
                // rev의 값에 따라 덱의 앞(front)에서 제거할지 뒤(back)에서 제거할지를 결정
                if (!rev)
                {
                    d.pop_front();
                }
                else
                {
                    d.pop_back();
                }
            }
        }

        if (isWrong) // isWrong이 true이면 "error"를 출력합니다. 이는 덱이 비었을 때 D 연산을 수행했을 경우 발생
        {
            cout << "error\n";
        }
        else
        {
            // rev가 1이면 덱을 뒤집어서 출력합니다. 그 후 덱의 모든 원소를 출력하는데, 각 원소 사이에 ','를 추가하여 출력
            if (rev)
                reverse(d.begin(), d.end()); // 뒤집기
            cout << '[';
            for (int i = 0; i < d.size(); i++)
            {
                cout << d[i];
                if (i + 1 != d.size())
                    cout << ',';
            }
            cout << "]\n";
        }
    }
}
