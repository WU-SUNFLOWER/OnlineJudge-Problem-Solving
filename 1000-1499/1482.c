#include <stdio.h>

long long int Fact[100] = {1};

int main() {
    int n;
    long long int s = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        Fact[i] = Fact[i - 1] * i;
        s += Fact[i];
    }
    printf("%lld\n", s);
}