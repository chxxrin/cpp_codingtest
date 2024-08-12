// 원소를 배열로 관리하고  pre와 nxt에 이전/다음 원소의 포인터 대신 배열상의 인덱스를 저장하는 방식으로 구현한 연결리스트

const int MX = 10000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1; 
fill(pre, pre+MX, -1);
fill(nxt, nxt+MX, -1);

메모리 누수 문제 때문에 실무에서는 x
dat[i] : i번지 원소 값
pre[i] : i번지 원소에 대해 이전 원소의 인덱스
다음 원소의 인덱스
pre, nxt 갑싱 -1이면 해당ㅇ 원소의 이전/다음 원소가 존재하지 않음
ㅎ현재 사용되지 않는 인데긋, 즉 새로운 원소가 들어갈 수 있는 인덱스
원소가 추가된 이후에는 1씩 증가
0번지느 ㄴ연결리스트의 시작 원소로 고정됨
즉, 0번지는 값이 들어가지 않고 단지 시작점을 나타내기 위한 더미코드
길이 : 따로 len 변수를 두고, 원소가 추가될 때 1증가, 제거될때 1감소시키면 됨


void traverse() {
    int cur = nxt[0];
    while(cur != -1) {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}