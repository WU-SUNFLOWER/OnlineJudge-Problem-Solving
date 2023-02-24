#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double son = 2;
    double mum = 1;
    double ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int oldSon = son;
        ans += son / mum;
        son = son + mum;
        mum = oldSon;
    }
    printf("%.6lf", ans);
}