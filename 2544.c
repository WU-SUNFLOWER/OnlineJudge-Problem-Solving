#include <stdio.h>

int getGCD(int a, int b) {
    int t;
    if (b > a) {
        t = a;
        a = b;
        b = t;
    }
    while (b > 0) {
        t = a;
        a = b;
        b = t % b;
    }
    return a;
}

int main() {
    int a;
    int b;
    int c;
    int d;
    while (~scanf("%d/%d * %d/%d", &b, &a, &d, &c)) {
        int son = b * d;
        int mum = a * c;
        int gcd = getGCD(son, mum);
        son /= gcd;
        mum /= gcd;
        printf("%d/%d * %d/%d = %d", b, a, d, c, son);
        if (mum != 1) {
            printf("/%d", mum);
        }
        putchar('\n');
    }
}