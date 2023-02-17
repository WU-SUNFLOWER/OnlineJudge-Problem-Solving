#include <stdio.h>
#include <math.h>

int main() {
    int num;
    int r;
    char ans[100];
    char map[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    while (~scanf("%d %d", &num, &r)) {
        int idx = -1;
        if (num < 0) {
            printf("-");
            num = -num;
        }
        while (num > 0) {
            int digit = num % r;
            ans[++idx] = digit < 10 ? (digit + '0') : map[digit - 10];
            num /= r;
        }
        for (; idx >= 0; idx--) {
            printf("%c", ans[idx]);
        }
        printf("\n");
    }
}