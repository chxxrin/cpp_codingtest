// 최대공약수
int gcd(int a, int b) {
    if(a==0) return b;
    return gcd(b%a, a);
}

// 최소공배수
int lcm(int a, int b) {
    return a/gcd(a,b)*b;
}

// 연립합동방정식
int chk() {
    for (int i=3;i<30;i+=6) {
        if(i%5 == 2) {
            return i;
        }
    }
    return -1;
}