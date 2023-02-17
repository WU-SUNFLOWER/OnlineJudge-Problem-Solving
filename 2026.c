#include <stdio.h>

int main() {
    int f[20] = {0, 1};
    for (int i = 2; i < 20; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    int m;
    int n;
    scanf("%d %d", &m, &n);
    if (m > n) {
        int t = m;
        m = n;
        n = t;
    }
    int sum = 0;
    for (; m <= n; m++) {
        sum += f[m];
    }
    printf("%d", sum);
}