#include <stdio.h>

int main() {
    double x;
    double ans;
    scanf("%lf", &x);
    if (x < 1) {
        ans = x;
    }
    else if (x >= 10) {
        ans = 3 * x - 11;
    }
    else {
        ans = 2 * x - 1;
    }
    printf("%g", ans);
}