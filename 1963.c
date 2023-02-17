#include <stdio.h>
#include <math.h>

int min(int a, int b) {
    return a > b ? b : a;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int num;
    int ans = 0;
    scanf("%d", &num);
    for (int i = 100; i <= min(num, 999); i++) {
        if (num % i == 0) {
            ans = max(ans, i);
        }
    }
    printf("%d", ans);
}