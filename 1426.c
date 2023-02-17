#include <stdio.h>

float Fact[60] = {1};

int main() {
    for (int i = 1; i < 60; i++) {
        Fact[i] = Fact[i - 1] * i;
    }
    int m;
    int n;
    scanf("%d %d", &m, &n);
    printf("%g\n", Fact[m] / (Fact[n] * Fact[m - n]));
}