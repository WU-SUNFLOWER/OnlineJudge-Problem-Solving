#include <stdio.h>
#include <math.h>

int main() {
    double a;
    double b;
    double c;
    double delta;
    double x1;  //ด๓
    double x2;  //ะก
    scanf("%lf %lf %lf", &a, &b, &c);
    delta = sqrt(pow(b, 2) - 4 * a * c);
    x1 = (-b + delta) /  (2 * a);
    x2 = (-b - delta) /  (2 * a);
    printf("%.2lf %.2lf", x1, x2);
}