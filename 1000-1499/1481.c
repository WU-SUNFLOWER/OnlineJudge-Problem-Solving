#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int ans = 0;
    int item[100] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        item[i] = item[i - 1] * 10 + 2;
        ans += item[i];
    }
    printf("%d", ans);
}