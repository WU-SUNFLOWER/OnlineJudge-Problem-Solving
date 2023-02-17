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
    scanf("%d %d", &a, &b);
    int gcd = getGCD(a, b);
    printf("%d %d", gcd, a * b / gcd);
}