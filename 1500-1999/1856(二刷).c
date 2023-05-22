#include <stdio.h>

int main() {
    int n = 0;
    int ar[100];
    while (~scanf("%d", &ar[n])) {
        n++;
    }
    int Max = -1 << 15;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        int max = -1 << 15;
        for (int j = i; j < n; j++) {
            cur += ar[j];
            if (cur > max) max = cur;
        }
        if (max > Max) Max = max;
    }
    printf("%d\n", Max);
}