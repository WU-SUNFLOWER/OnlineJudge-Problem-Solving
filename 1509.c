#include <stdio.h>
#define max(a, b) a > b ? a : b

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("%.3lf\n", max(max(a, b), c));
    printf("%.3lf\n", max(max(a, b), c));
}