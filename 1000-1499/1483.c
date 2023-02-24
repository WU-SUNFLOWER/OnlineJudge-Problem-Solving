#include <stdio.h>

int main() {
    int a;
    int b;
    int c;
    double sum = 0;
    scanf("%d %d %d", &a, &b, &c);
    for (int i = 1; i <= a; i++) {
        sum += i;
    }
    for (int i = 1; i <= b; i++) {
        sum += i * i;
    }
    for (int i = 1; i <= c; i++) {
        sum += 1.0 / i;
    }
    printf("%.2lf", sum);
}