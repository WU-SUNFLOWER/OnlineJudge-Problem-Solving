#include <stdio.h>

int main() {
    int peopleNum;
    int step;
    scanf("%d %d", &peopleNum, &step);
    int f[100] = {0};
    for (int i = 1; i <= peopleNum; i++) {
        f[i] = (f[i - 1] + step) % i;
    }
    printf("%d\n", f[peopleNum] + 1);
}