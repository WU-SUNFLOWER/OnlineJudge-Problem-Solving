#include <stdio.h>
#include <math.h>

int main() {
    double x;
    double ans;
    scanf("%lf", &x);
    if (x < 0) {
        ans = -x;
    }
    else if (0 <= x && x < 2) {
        ans = pow(x + 1, 0.5);
    }
    else if (2 <= x && x < 4) {
        ans = pow(x + 2, 5);
    }
    else {
        ans = 2 * x + 5;
    }
    printf("%.2lf\n", ans);
}