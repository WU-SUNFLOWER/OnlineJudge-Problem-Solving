#include <stdio.h>
#include <math.h>

int main() {
    double a;
    double b;
    double c;
    while (~scanf("%lf %lf %lf", &a, &b, &c)) {
        double x1;
        double x2;
        double delta = b * b - 4 * a * c;
        if (delta >= 0) {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("%.2lf %.2lf\n", x1, x2);
        } else {
            printf("NO\n");
        }        
    }
}