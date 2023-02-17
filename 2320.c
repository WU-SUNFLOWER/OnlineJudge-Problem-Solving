#include <stdio.h>

int main() {
    int input;
    int f[41] = {0, 1, 1};
    for (int i = 3; i <= 40; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    while (~scanf("%d", &input)) {
        printf("%d\n", f[input]);
    }
}