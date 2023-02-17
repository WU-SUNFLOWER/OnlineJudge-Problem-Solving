#include <stdio.h>
#include <math.h>
#define S(a, b, c) (a + b + c) / 2
#define Area(S, a, b, c) sqrt(S*(S-a)*(S-b)*(S-c))

int main() {
    double a;
    double b;
    double c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double s = S(a, b, c);
    printf("%.3lf", Area(s, a, b, c));
}