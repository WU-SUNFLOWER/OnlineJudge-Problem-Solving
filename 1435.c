#include <stdio.h>
#include <math.h>
#define N 1000

int main() {
    int left;
    int right;
    int isNotPrime[N] = {0, 1, 0};
    scanf("%d %d", &left, &right);
    int ans = 0;
    for (int i = 2; i <= sqrt(right); i++) {
        if (!isNotPrime[i]) {
            for (int j = 2; i * j <= right; j++) {
                isNotPrime[i * j] = 1;
            }
        }
    }
    for (int i = left; i <= right; i++) {
        !isNotPrime[i] && (ans += i);
    }
    printf("%d\n", ans);
}