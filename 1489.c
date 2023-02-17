#include <stdio.h>
#include <math.h>

int main() {
    double a;
    double x1;
    double x2 = 1;
    scanf("%lf", &a);
    do {
        x1 = x2;
        x2 = 0.5 * (x1 + a / x1);
    } while (fabs(x1 - x2) >= 0.00001);
    printf("%.3lf\n", x2);
}