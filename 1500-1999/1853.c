#include <stdio.h>

int gcd(int a, int b) {
    while (b > 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a * b / gcd(a, b));
}