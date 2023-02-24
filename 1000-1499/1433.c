#include <stdio.h>

int main() {
    int n;
    float sum = 0;
    float mum = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        mum *= i;
        sum += 1 / mum;
    }
    printf("%.4f\n", sum);
}