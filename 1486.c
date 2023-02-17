#include <stdio.h>

int main() {
    int n;
    double sum = 2;
    double son[100] = {2};
    double mum[100] = {1};
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        son[i] = son[i - 1] + mum[i - 1];
        mum[i] = son[i - 1];
        sum += son[i] / mum[i];
    }
    printf("%.2lf\n", sum);
}