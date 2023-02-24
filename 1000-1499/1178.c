#include <stdio.h>

int main() {
    int num;
    int ans[100];
    int idx = -1;
    scanf("%d", &num);
    while (num > 0) {
        ans[++idx] = num % 10;
        num /= 10;
    }
    while (idx >= 0) {
        printf(idx == 0 ? "%d\n" : "%d ", ans[idx]);
        idx--;
    }
}