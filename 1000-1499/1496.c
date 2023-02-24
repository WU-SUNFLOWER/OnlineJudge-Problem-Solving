#include <stdio.h>
#include <math.h>

int main() {
    double a;
    double b;
    double c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double x1;
    double x2;
    double delta = b * b - 4 * a * c;
    if (delta >= 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("x1=%.3lf x2=%.3lf", x1, x2);
    } else {
        double p = -b / (2 * a);
        double q = sqrt(-delta) / (2 * a);
        printf("x1=%.3lf+%.3lfi x2=%.3lf-%.3lfi", p, q, p, q);
    }
}