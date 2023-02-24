#include <stdio.h>

int main() {
    double f;
    scanf("%lf", &f);
    printf("c=%.2lf", 5 * (f - 32) / 9);
}