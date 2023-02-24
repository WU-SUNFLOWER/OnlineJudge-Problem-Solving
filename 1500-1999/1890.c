#include <stdio.h>

int main() {
    int f[10];
    f[9] = 1;
    for (int i = 9; i >= 1; i--) {
        f[i - 1] = 2 * f[i] + 2;
    }
    printf("%d", f[0]);
}