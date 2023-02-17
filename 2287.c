#include <stdio.h>

int main() {
    int n;
    int f[21] = {0, 1};
    for (int i = 2; i <= 20; i++) {
        f[i] = f[i - 1] * 2 + 1;
    }
    while (~scanf("%d", &n) && n > 0) {
        printf("%d\n", f[n]);
    }
}