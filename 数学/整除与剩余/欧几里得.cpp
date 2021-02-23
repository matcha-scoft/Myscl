#include <iostream>
using namespace std;

/*
    任务：求两个数a, b的最大公约数gcd(a, b)
    接口：int gcd(int a, int b);
    复杂度：O(logn)
    输入：a,b
    输出：gcd(a, b)
*/
int gcd(int a, int b) {
    return b == 0? a : gcd(b, a % b);
}

/*
    扩展欧几里得
    任务：求出A，B的最大公约数，且求出X，Y满足：AX + BY = GCD(A, B)
    接口：int extend_gcd(int a, int b, int &x, int &y);
    复杂度：O(logn)
*/
int extend_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        int r = extend_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}
