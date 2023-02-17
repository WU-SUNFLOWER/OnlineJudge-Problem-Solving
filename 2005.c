#include <stdio.h>
#include <math.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int left;
    int right;
    int idx = -1;
    int ans[4];
    scanf("%d %d", &left, &right);
    for (int i = left; i <= min(right, 999); i++) {
        int a = i % 10;
        int b = i / 10 % 10;
        int c = i / 100;
        if (pow(a, 3) + pow(b, 3) + pow(c, 3) == i) {
            ans[++idx] = i;
        }
    }
    if (idx < 0) {
        printf("No Armstrong numbers between %d and %d\n", left, right);
    } else {
        printf("Armstrong numbers between %d and %d:\n", left, right);
        for (int i = 0; i <= idx; i++) {
            printf(i == idx ? "%d\n" : "%d ", ans[i]);
        }
    }
}