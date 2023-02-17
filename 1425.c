#include <stdio.h>

int main() {
    int n;
    double sum = 0;
    double mum = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        mum *= i;
        sum += 1 / mum;
    }
    printf("sum=%.5lf\n", sum);
}