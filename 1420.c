#include <stdio.h>
#include <math.h>

int main() {
    //x - x2/2! + x3/3! + ... + (-1)n-1xn/n!
    int n;
    double x;
    double sum = 0;
    double mum = 1;
    scanf("%lf %d", &x, &n);
    for (int i = 1; i <= n; i++) {
        mum *= i;
        sum += pow(-1, i - 1) * pow(x, i) / mum;
    }
    printf("%.4lf\n", sum);
}